n,m,l=map(int,input().split())
a=map(int,input().split())
d=[i==m for i in range(l+1)]
for x in a:
	d=[i-x>=0 and d[i-x] or i+x<=l and d[i+x] for i in range(l+1)]
try:
	i=d[::-1].index(1)
	print(l-i)
except:
	print(-1)