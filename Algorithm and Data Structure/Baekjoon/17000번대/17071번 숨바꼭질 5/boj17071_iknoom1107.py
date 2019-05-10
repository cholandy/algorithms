M=500000
g=[[-1]*(M+1) for _ in range(2)]
N,K=map(int,input().split())
g[0][N]=0
q=[(N,0)]
for x,r in q:
	k=(r+1)%2
	if 0<=x-1 and g[k][x-1]<0:g[k][x-1]=g[r][x]+1;q.append((x-1,k))
	if x+1<=M and g[k][x+1]<0:g[k][x+1]=g[r][x]+1;q.append((x+1,k))
	if x*2<=M and g[k][x*2]<0:g[k][x*2]=g[r][x]+1;q.append((x*2,k))
T=0
S=False
while K+T<=M:
	K+=T;r=T%2
	if g[r][K]<=T:S=True;break
	T+=1
print(T if S else -1)