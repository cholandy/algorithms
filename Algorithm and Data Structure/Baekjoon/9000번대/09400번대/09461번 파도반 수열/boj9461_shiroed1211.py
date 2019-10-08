import sys
n = int(sys.stdin.readline())
dp = [1, 1, 1, 1, 2, 2,]
for i in range(6,101):
    dp.append(dp[i-1] + dp[i-5])
for _ in range(n):
    tmp = int(sys.stdin.readline())
    print(dp[tmp])