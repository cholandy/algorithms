import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=sorted(int(input()) for i in range(n))
j=0
r=9876543210
for i in range(n):
	while j<n and a[j]-a[i]<m:
		j+=1
	if j<n:
		r=min(r,a[j]-a[i])
print(r)