n=int(input())
d=[[0]*3 for i in range(1111)]
for i in range(1,n+1):
  a=list(map(int,input().split()))
  for j in range(3):
    d[i][j]=10**10
    for k in range(3):
      if j!=k:
        d[i][j]=min(d[i][j],d[i-1][k])
    d[i][j]+=a[j]
print(min(d[n]))