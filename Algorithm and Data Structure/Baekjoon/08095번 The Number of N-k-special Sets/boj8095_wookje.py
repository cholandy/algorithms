n, k = list(map(int, input().split(' ')))
dp = [[0]*402 for _ in range(101)]
dp[0][0] = dp[1][1] = 1
dp[1][0] = 2
for i in range(2, n+1):
    for j in range(k+2):
        dp[i][j] = dp[i-1][j] + dp[i-2][max(0, j-i)]
print(dp[n][k+1])