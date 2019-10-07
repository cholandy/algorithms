import sys
input=sys.stdin.readline
n=int(input())
a=[list(map(int, input().split())) for i in range(n)]
p=q=r=0
def f(x,y,z):
    for i in range(z):
        for j in range(z):
            if a[x][y]!=a[x+i][y+j]:
                f(x,y,z//3)
                f(x,y+z//3,+z//3)
                f(x,y+z//3+z//3,z//3)
                f(x+z//3,y,z//3)
                f(x+z//3,y+z//3,z//3)
                f(x+z//3,y+z//3+z//3,z//3)
                f(x+z//3+z//3,y,z//3)
                f(x+z//3+z//3,y+z//3,z//3)
                f(x+z//3+z//3,y+z//3+z//3,z//3)
                return
    global p,q,r
    if a[x][y]==-1:
        p+=1
    if a[x][y]==0:
        q+=1
    if a[x][y]==1:
        r+=1
f(0,0,n)
print(p)
print(q)
print(r)