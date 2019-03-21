n=int(input())
a=list(map(int,input().split()))
m=int(input())
mn=0
mx=1111
for i in range(n):
    if a[i]<=m:
        mn=max(mn,a[i])
    if a[i]>=m:
        mx=min(mx,a[i])
print(max((m-mn)*(mx-m)-1,0))