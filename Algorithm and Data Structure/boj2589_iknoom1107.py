N,M=map(int,input().split())
g=[input() for _ in range(N)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
ans=0
s=[]
for j in range(N):
	for i in range(M):
		if g[j][i]=='L':
			vst=[[-1]*M for _ in range(N)]
			s=[(i,j)]
			vst[j][i]=0
			for x,y in s:
				for d in range(4):
					n=x+dx[d]
					m=y+dy[d]
					if 0<=n<M and 0<=m<N and g[m][n]=='L' and vst[m][n]<0:
						vst[m][n]=vst[y][x]+1
						s.append((n,m))
			ans=max(ans,vst[y][x])
print(ans)