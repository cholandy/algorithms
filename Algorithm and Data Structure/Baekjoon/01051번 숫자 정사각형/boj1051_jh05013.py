n, m = map(int,input().split())
grid = [input() for i in range(n)]
ans = 0

lim = min(n, m)
for d in range(1, lim+1):
    for i in range(n-d+1):
        for j in range(m-d+1):
            if grid[i][j] == grid[i+d-1][j] == grid[i][j+d-1] == grid[i+d-1][j+d-1]:
                ans = max(ans, d**2)
print(ans)