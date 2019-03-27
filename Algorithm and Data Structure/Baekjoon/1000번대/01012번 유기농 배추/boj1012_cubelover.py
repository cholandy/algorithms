import sys
sys.setrecursionlimit(3333)
for tc in range(int(input())):
    n,m,l=map(int,input().split())
    d=[[0]*m for i in range(n)]
    for i in range(l):
        x,y=map(int,input().split())
        d[x][y]=1
    def f(i,j):
        global d,n,m
        if i<0 or i>=n or j<0 or j>=m or not d[i][j]:
            return
        d[i][j]=0
        f(i+1,j)
        f(i-1,j)
        f(i,j+1)
        f(i,j-1)
    r=0
    for i in range(n):
        for j in range(m):
            if d[i][j]:
                r+=1
                f(i,j)
    print(r)