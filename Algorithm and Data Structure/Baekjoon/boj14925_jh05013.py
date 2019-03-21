n, m = map(int,input().split())
grid = [list(map(int,input().split())) for i in range(n)]
dp = [[0]*m for i in range(n)]
for i in range(n):
    for j in range(m):
        if grid[i][j]: continue
        if i==0 or j==0: dp[i][j] = 1; continue
        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
print(max(map(max,dp)))