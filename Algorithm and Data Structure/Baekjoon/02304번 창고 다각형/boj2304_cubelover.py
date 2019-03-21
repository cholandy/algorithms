import sys
input=sys.stdin.readline
l=[0]*1111
r=[0]*1111
for i in range(int(input())):
    a,b=map(int,input().split())
    l[a]=r[a]=b
for i in range(1,1111):
    l[i]=max(l[i],l[i-1])
for i in range(1109,-1,-1):
    r[i]=max(r[i],r[i+1])
a=t=sum(r)
for i in range(0,1111):
    t-=r[i]
    t+=l[i]
    a=min(a,t)
print(a)