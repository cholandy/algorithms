input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())

n, m, k = MIS()
adj = [[] for i in range(n+1)]
for i in range(k):
    a, b, c = MIS()
    if a > b: continue
    adj[a].append((b,c))

INF = 10**12
dp = [[-INF]*(m+1) for i in range(n+1)]
dp[1][1] = 0
# city i, visit j
for i in range(1, n):
    for j in range(1, m):
        for b, c in adj[i]:
            dp[b][j+1] = max(dp[b][j+1], dp[i][j]+c)
print(max(dp[n]))