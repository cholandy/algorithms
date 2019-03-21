from sys import stdin
n = int(input())
a = list(map(int, input().split()))
for i in range(1, n):
    x, y = map(int, stdin.readline().split())
    a.append(y)
dp = [[0 for i in range(n+1)] for j in range(n+1)]
for len in range(2, n+1):
    for i in range(1, n + 2 - len):
        j = i + len - 1
        dp[i][j] = 1000000000
        for k in range(i, j):
            cost = dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j]
            dp[i][j] = min(dp[i][j], cost)
print(dp[1][n])