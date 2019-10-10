import sys
sys.stdin = open('input.txt', 'r')
for _ in range(int(input())):
    N, M = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]
    dp = [[0] * (N-1) for _ in range(N-1)]
    # [print(*i) for i in dp]
    ans = 0
    for i in range(1, N):
        for j in range(1, N):
            dp[i][j] = sum(grid[x][y] for x in range())
            ans = max(ans, dp[i][j])
