n, m = map(int,input().split())
mat = [[1]*n for i in range(n)]
for i in range(n):
    mat[i][i] = 0
for i in range(m):
    a, b = map(int,input().split())
    a-=1; b-=1
    mat[a][b] = 0
    mat[b][a] = 0

res = 0
for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            if mat[i][j] and mat[j][k] and mat[k][i]: res+= 1
print(res)