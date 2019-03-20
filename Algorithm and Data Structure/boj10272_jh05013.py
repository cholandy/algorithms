from sys import setrecursionlimit as SRL, stdin
SRL(55555)
input = stdin.readline
range = xrange

def update(i, j):
    nx = max(i, j) + 1
    if nx == n: return
    dp[nx][j] = min(dp[nx][j], dp[i][j]+dist(i,nx))
    dp[i][nx] = min(dp[i][nx], dp[i][j]+dist(j,nx))

def dist(i, j):
    xi, yi = p[i]
    xj, yj = p[j]
    return ((xi-xj)**2 + (yi-yj)**2) ** 0.5

for TEST in range(int(input())):
    n = int(input())
    p = [tuple(map(int,input().split())) for i in range(n)]
    dp = [[float('inf')]*n for i in range(n)]
    dp[0][0] = 0
    for v in range(n):
        # update [v+1][j]
        for i in range(v+1): update(i, v)
        for j in range(v): update(v, j)
    finish = [dp[i][n-1] + dist(i, n-1) for i in range(n)]\
        + [dp[n-1][j] + dist(n-1, j) for j in range(n)]
    print(min(finish))