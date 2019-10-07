n=int(input())
a=[1]*(n+1)
for i in range(int(input())):
	a[int(input())]=0
d=[1 for i in range(n+1)]
for i in range(2,n+1):
	d[i]=d[i-1]
	if a[i] and a[i-1]:
		d[i]+=d[i-2]
print(d[n])