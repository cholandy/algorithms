import bisect
n,m=map(int,input().split())
a=list(map(int,input().split()))
x=[]
for i in range(1<<n//2):
  t=0
  for j in range(n//2):
    if i>>j&1:
      t+=a[j]
  x.append(t)
x.sort()
r=0
for i in range(1<<(n+1)//2):
  t=m
  for j in range((n+1)//2):
    if i>>j&1:
      t-=a[j+n//2]
  r+=bisect.bisect_right(x,t)-bisect.bisect_left(x,t)
print(r-(not m))