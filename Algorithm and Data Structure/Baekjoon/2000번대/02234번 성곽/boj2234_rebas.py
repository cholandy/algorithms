dx, dy = (0, -1, 0, 1), (-1, 0, 1, 0)
A, B, C = 0, 0, 0
n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(m)]
check = [[0]*n for _ in range(m)]
area = [0]*(n*m+1)

def dfs(x, y, z):
    check[x][y] = z
    res = 1
    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]
        if not ((a[x][y] & (1<<i)) or check[nx][ny]):
            res += dfs(nx, ny, z)
    return res

for i in range(m):
    for j in range(n):
        if not check[i][j]:
            A += 1
            k = dfs(i, j, A)
            B = max(B, k)
            area[A] = k
for i in range(m):
    for j in range(n):
        for k in range(4):
            ni, nj = i+dx[k], j+dy[k]
            if ni < 0 or ni >= m or nj < 0 or nj >= n:
                continue
            x, y = check[i][j], check[ni][nj]
            if x != y:
                C = max(C, area[x]+area[y])
print("%d\n%d\n%d" % (A, B, C))


