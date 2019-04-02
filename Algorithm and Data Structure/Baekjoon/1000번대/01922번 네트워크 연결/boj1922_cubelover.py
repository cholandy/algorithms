n=int(input())
m=int(input())
d=[[] for i in range(m)]
for i in range(m):
    a,b,c=map(int,input().split())
    d[i]=(c,b,a)
d.sort()
p=list(range(n+1))
def f(x):
    if x==p[x]:
        return x
    p[x]=f(p[x])
    return p[x]
r=0
for i in range(m):
    if f(d[i][1])!=f(d[i][2]):
        p[f(d[i][1])]=f(d[i][2])
        r+=d[i][0]
print(r)