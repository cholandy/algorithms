import sys
input=sys.stdin.readline
n=int(input())
g=[[] for i in range(n)]
a=[]
d=[0]*n
v=[0]*n
q=[]
for i in range(n):
    t=list(map(int,input().split()))
    a.append(t[0])
    v[i]=t[1]
    if not t[1]:
        q.append(i)
    for x in t[2:]:
        g[x-1].append(i)
for x in q:
    d[x]+=a[x]
    for y in g[x]:
        d[y]=max(d[y],d[x])
        v[y]-=1
        if not v[y]:
            q.append(y)
print(max(d))