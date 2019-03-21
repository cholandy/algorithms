n = int(input())
l = list(map(int, input().split()))

dp = [[0,0] for i in range(n)]

dp[0][0] = l[0]

for i in range(1,n):
    dp[i][0] = max(dp[i-1][0]+l[i], l[i])
    dp[i][1] = max(dp[i-1][0], dp[i-1][1]+l[i])

dp[0][1] = -1001

print(max(max(dp[i][0],dp[i][1]) for i in range(n)))
