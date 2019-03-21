r=0;n,k=map(int,input().split())
p=[[0 for _ in'_'*(k+1)]for _ in'_'*101]
for i in range(1,n+1):
    a,b,c,d=map(int,input().split())
    for j in range(k+1):
        if p[i-1][j] or(i==1 and j==0):
            if a+j<=k:p[i][a+j]=max(p[i][a+j],b+p[i-1][j])
            if c+j<=k:p[i][c+j]=max(p[i][c+j],d+p[i-1][j])
            if p[n][j]>r:r=p[n][j]
print(r)