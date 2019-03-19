n=int(input())
a=list(map(int,input().split()))
d=[0]*n
p=[0]*n
for i in range(n):
	d[i]=1
	if a[i]>1:
		d[i]=p[a[i]-2]+1
	p[a[i]-1]=d[i]
print(n-max(d))