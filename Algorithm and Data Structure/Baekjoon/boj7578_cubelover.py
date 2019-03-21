import sys
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
d=[0]*1000001
for i in range(n):
	d[a[i]]=n-i
a=list(map(int,input().split()))
t=[0]*1000001
r=0
for i in a:
	j=d[i]
	while j:
		r+=t[j]
		j-=j&-j
	j=d[i]
	while j<=n:
		t[j]+=1
		j+=j&-j
print(r)