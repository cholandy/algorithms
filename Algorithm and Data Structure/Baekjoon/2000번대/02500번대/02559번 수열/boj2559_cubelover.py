n,m=map(int,input().split())
a=list(map(int,input().split()))
d=[0]
for i in range(n):
    d.append(d[i]+a[i])
r=-987654321
for i in range(m,n+1):
    r=max(r,d[i]-d[i-m])
print(r)