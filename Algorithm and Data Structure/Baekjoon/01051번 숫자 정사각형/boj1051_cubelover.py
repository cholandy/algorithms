n,m=map(int,input().split())
a=[input() for i in range(n)]
r=1
for i in range(n):
    for j in range(m):
        for k in range(min(i,j)):
            if a[i][j]==a[i-k-1][j]==a[i][j-k-1]==a[i-k-1][j-k-1]:
                r=max(r,(k+2)**2)
print(r)