n=int(input())
a=[list(map(int,input().split())) for i in range(n)]
d=[[0]*n for i in range(n)]
d[n-1][n-1]=1
for i in range(n):
    for j in range(n):
        if a[n-i-1][n-j-1]:
            if i>=a[n-i-1][n-j-1]:
                d[n-i-1][n-j-1]+=d[n-i-1+a[n-i-1][n-j-1]][n-j-1]
            if j>=a[n-i-1][n-j-1]:
                d[n-i-1][n-j-1]+=d[n-i-1][n-j-1+a[n-i-1][n-j-1]]
print(d[0][0])