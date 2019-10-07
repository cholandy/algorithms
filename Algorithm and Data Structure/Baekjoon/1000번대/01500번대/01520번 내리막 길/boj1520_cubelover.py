n,m=map(int,input().split())
a=[]
c=[]
for i in range(n):
	a.append(list(map(int,input().split())))
	for j in range(m):
		c.append([-a[i][j],i,j])
c.sort()
d=[[0]*m for i in range(n)]
for x in c:
	i=x[1]
	j=x[2]
	if i==0 and j==0:
		d[i][j]=1
	if i>0 and a[i-1][j]>a[i][j]:
		d[i][j]+=d[i-1][j]
	if i+1<n and a[i+1][j]>a[i][j]:
		d[i][j]+=d[i+1][j]
	if j>0 and a[i][j-1]>a[i][j]:
		d[i][j]+=d[i][j-1]
	if j+1<m and a[i][j+1]>a[i][j]:
		d[i][j]+=d[i][j+1]
print(d[n-1][m-1])