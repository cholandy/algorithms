import sys
sys.setrecursionlimit(100000)

def dfs(x, y, z):
    check[x][y] = True
    for dx, dy in (-1,0), (1,0), (0,-1), (0,1):
        nx, ny = x+dx, y+dy
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        if not check[nx][ny] and a[nx][ny] > z:
            dfs(nx, ny, z)

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
ans = 0
for k in range(max(max(a))):
    check = [[False]*n for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(n):
            if not check[i][j] and a[i][j] > k:
                dfs(i, j, k)
                cnt += 1
    ans = max(ans, cnt)
print(ans)


