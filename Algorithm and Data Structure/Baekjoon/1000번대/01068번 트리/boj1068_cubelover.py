n=int(input())
a=list(map(int,input().split()))
g=[[] for i in range(n)]
m=int(input())
for i in range(n):
    if a[i]<0:
        ro=i
    elif i!=m and a[i]!=m:
        g[a[i]].append(i)
r=0
def f(x):
    global r
    if len(g[x])==0:
        r+=1
    for i in g[x]:
        f(i)
if m!=ro:
    f(ro)
print(r)