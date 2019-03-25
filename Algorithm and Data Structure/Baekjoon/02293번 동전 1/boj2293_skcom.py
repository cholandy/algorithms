import sys
n, k = list(map(int, input().split()))
coin = list(map(int, sys.stdin.readlines()))
dp = [0]*(k+1)
dp[0] = 1

for i in range(n):
    for j in range(k+1):
        if(j-coin[i] >= 0):
            dp[j] += dp[j-coin[i]]
print(dp[k])

