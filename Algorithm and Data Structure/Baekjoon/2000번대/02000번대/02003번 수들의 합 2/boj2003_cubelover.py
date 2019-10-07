n,m=map(int,input().split())
a=list(map(int,input().split()))
j=s=r=0
for i in range(n):
    s+=a[i]
    while s>m:
        s-=a[j]
        j+=1
    if s==m:
        r+=1
print(r)