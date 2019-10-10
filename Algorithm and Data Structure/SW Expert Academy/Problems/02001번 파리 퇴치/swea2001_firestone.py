import sys
sys.stdin = open('input.txt', 'r')
for _ in range(int(input())):
    N, M = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]
    # dp = [[0] * (N-1) for _ in range(N-1)]
    # [print(*i) for i in dp]
    ans = 0
    for i in range(M-1, N):
        for j in range(M-1, N):
            # dp[i-1][j-1] = sum(grid[x][y] for x in range(i+1-M, i+1)
            #                    for y in range(j+1-M, j+1))
            ans = max(ans, sum(grid[x][y] for x in range(i+1-M, i+1)
                               for y in range(j+1-M, j+1)))
    print("#{} {}".format(_+1, ans))
