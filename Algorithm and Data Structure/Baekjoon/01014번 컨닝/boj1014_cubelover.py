import sys
sys.setrecursionlimit(11111)
for tc in range(int(input())):
	n,m=map(int,input().split())
	a=[input() for i in range(n)]
	l=n*m+2
	g=[[0]*l for i in range(l)]
	r=0
	for i in range(n):
		for j in range(m):
			if a[i][j]=='x':
				continue
			r+=1
			if j&1:
				g[l-2][i*m+j]=1
				if i>0:
					if j>0:
						g[i*m+j][i*m+j-m-1]=1
					if j+1<m:
						g[i*m+j][i*m+j-m+1]=1
				if i+1<n:
					if j>0:
						g[i*m+j][i*m+j+m-1]=1
					if j+1<m:
						g[i*m+j][i*m+j+m+1]=1
				if j>0:
					g[i*m+j][i*m+j-1]=1
				if j+1<m:
					g[i*m+j][i*m+j+1]=1
			else:
				g[i*m+j][l-1]=1
	def f(x):
		global l,g,v
		if v[x]:
			return 0
		if x==l-1:
			return 1
		v[x]=1
		for i in range(l):
			if g[x][i] and f(i):
				g[x][i]-=1
				g[i][x]+=1
				return 1
	v=[0]*l
	while f(l-2):
		v=[0]*l
		r-=1
	print(r)