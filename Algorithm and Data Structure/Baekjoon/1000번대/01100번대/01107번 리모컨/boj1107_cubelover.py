import sys
input=sys.stdin.readline
n=int(input())
m=int(input())
if m:
    a=list(map(int,input().split()))
d=[1]*10
for i in range(m):
    d[a[i]]=0
r=abs(n-100)
if d[0]:
    r=min(r,n+1)
for i in range(1,1111112):
    t=abs(i-n)
    j=i
    flag=1
    while j:
        if d[j%10]==0:
            flag=0
        j//=10
        t+=1
    if flag:
        r=min(r,t)
print(r)