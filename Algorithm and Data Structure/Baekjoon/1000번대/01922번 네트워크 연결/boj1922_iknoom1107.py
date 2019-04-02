import sys
input=sys.stdin.readline
N=int(input())
M=int(input())
w=[tuple(map(int,input().split())) for _ in range(M)]
w.sort(key=lambda x:x[2])
p=[i for i in range(N)]
def f(u):
	if u!=p[u]:p[u]=f(p[u])
	return p[u]	
e=ans=0
for u,v,c in w:
	if f(u-1)!=f(v-1):p[f(u-1)]=p[f(v-1)];ans+=c;e+=1
	if e==N-1:break
print(ans)