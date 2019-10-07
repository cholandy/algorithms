import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=[[1]*n for i in range(n)]
for i in range(m):
    x,y=map(int,input().split())
    a[x-1][y-1]=a[y-1][x-1]=0
r=0
for i in range(n):
    for j in range(i):
        for k in range(j):
            if a[i][j] and a[j][k] and a[k][i]:
                r+=1
print(r)