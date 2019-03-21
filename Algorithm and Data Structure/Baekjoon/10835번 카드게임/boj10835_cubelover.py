import sys
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
d=[[-987654321]*(n+1) for i in range(n+1)]
d[0][0]=0
for i in range(n):
    for j in range(n):
        if d[i][j] > d[i+1][j]:
            d[i+1][j] = d[i][j]
        if d[i][j] > d[i+1][j+1]:
            d[i+1][j+1] = d[i][j]
        if b[j]<a[i] and d[i][j] + b[j] > d[i][j+1]:
            d[i][j+1] = d[i][j] + b[j]
print(max(map(max, d)))