import sys
input=sys.stdin.readline
n=int(input())
g=[[] for i in range(n)]
for i in range(n):
	a=list(map(int,input().split()))
	for j in range(len(a)//2-1):
		g[a[0]-1].append([a[j+j+1]-1,a[j+j+2]])
def f(x,y,z):
    global g,v
    v[x]=z
    for w,t in g[x]:
        if w!=y:
            f(w,x,z+t)
v=[0]*n
f(0,-1,0)
t=v.index(max(v))
f(t,-1,0)
print(max(v))