import sys
input=sys.stdin.readline
n=int(input())
d=[[0]*111 for i in range(111)]
for i in range(n):
    x,y=map(int,input().split())
    for j in range(10):
        for k in range(10):
            d[x+j+5][y+k+5]=1
r=0
for i in range(2,110):
    for j in range(2,110):
        r+=(d[i][j]!=d[i-1][j])+(d[i][j]!=d[i][j-1])
print(r)