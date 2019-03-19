from sys import stdin
read = lambda: stdin.readline().rstrip()
n, m, k = map(int, input().split())
d = {i:set() for i in range(1, n+1)}
arr = [[0]*(n+1) for _ in range(n+1)]
for _ in range(k):
    a, b, c = map(int, read().split())
    if a < b:
        arr[a][b] = max(arr[a][b], c)
        d[a].add(b)
dp = [[0]*(m+1) for _ in range(n+1)]
for j in d[1]:
    dp[j][2] = arr[1][j]
for i in range(2, n):
    for j in range(2, m):
        if dp[i][j] > 0:
            for k in d[i]:
                dp[k][j+1] = max(dp[k][j+1], dp[i][j]+arr[i][k])
print(max(dp[-1]))