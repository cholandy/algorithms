n,m=map(int,input().split())
a=[list(map(int,input().split())) for i in range(n)]
m,l=map(int,input().split())
b=[list(map(int,input().split())) for j in range(m)]
c=[[sum(a[i][j]*b[j][k] for j in range(m)) for k in range(l)] for i in range(n)]
for i in range(n):
    print(' '.join(str(x) for x in c[i]))