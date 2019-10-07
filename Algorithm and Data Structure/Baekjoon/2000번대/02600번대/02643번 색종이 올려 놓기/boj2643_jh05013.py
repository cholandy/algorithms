n = int(input())
p = [tuple(sorted(map(int,input().split()))) for i in range(n)]
dp = [0]*n

def cal(i):
    if dp[i]: return dp[i]
    dp[i] = 1
    for j in range(n):
        if i == j: continue
        if p[i][0] >= p[j][0] and p[i][1] >= p[j][1]:
            dp[i] = max(dp[i], cal(j)+1)
    return dp[i]

print(max(cal(i) for i in range(n)))