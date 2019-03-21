k, n = map(int,input().split())
dp = [0]*128
dp[k] = 1 if k else 0
old = [0]*128
for i in range(n):
    dp, old = old, dp
    for j in range(1, 127): dp[j] = old[j-1] + old[j+1]
print(sum(dp))