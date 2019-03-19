n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a.sort()
b.sort()
i=j=0
r=n+m
while i<n and j<m:
    if a[i]==b[j]:
        r-=2
    if a[i]<b[j]:
        i+=1
    else:
        j+=1
print(r)