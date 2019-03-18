import sys
input=sys.stdin.readline
N=int(input())
M=int(input())
g=[[sys.maxsize]*N for _ in range(N)]
for _ in range(M):
	a,b,w=map(int,input().split())
	g[a-1][b-1]=min(g[a-1][b-1],w)
for k in range(N):
	for i in range(N):
		for j in range(N):
			if i!=j:g[i][j]=min(g[i][j],g[i][k]+g[k][j])
for y in g:
	print(*(s if s<sys.maxsize else 0 for s in y),end=' ')
	print()