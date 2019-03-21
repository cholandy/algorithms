import sys
input=sys.stdin.readline

l,m,n=map(int,input().split())
a=[[list(map(int,input().split())) for j in range(m)] for i in range(n)]
d=[[[-1]*l for j in range(m)] for i in range(n)]
q=[]
for i in range(n):
    for j in range(m):
        for k in range(l):
            if a[i][j][k]==1:
                d[i][j][k]=0
                q.append((i,j,k))
def f(x,y,z,w):
    if 0<=x<n and 0<=y<m and 0<=z<l and a[x][y][z]!=-1 and d[x][y][z]==-1:
        d[x][y][z]=w
        q.append((x,y,z))
for x,y,z in q:
    f(x+1,y,z,d[x][y][z]+1)
    f(x-1,y,z,d[x][y][z]+1)
    f(x,y+1,z,d[x][y][z]+1)
    f(x,y-1,z,d[x][y][z]+1)
    f(x,y,z+1,d[x][y][z]+1)
    f(x,y,z-1,d[x][y][z]+1)
flag=1
r=0
for i in range(n):
	for j in range(m):
		for k in range(l):
			if a[i][j][k]!=-1 and d[i][j][k]==-1:
				flag=0
			r=max(r,d[i][j][k])
if flag:
    print(r)
else:
    print(-1)