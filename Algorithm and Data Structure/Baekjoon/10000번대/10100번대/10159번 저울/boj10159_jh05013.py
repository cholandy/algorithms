def FloydWarshall(n, cost):
    for i in range(n): cost[i][i] = 0
    for k in range(n):
        for i in range(n):
            for j in range(n): cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])

n = int(input())
m = int(input())
adj = [[float('inf')]*n for i in range(n)]
for i in range(m):
    a, b = map(int,input().split())
    a-= 1; b-= 1
    adj[a][b] = 1
FloydWarshall(n, adj)

for i in range(n):
    un = 0
    for j in range(n):
        if min(adj[i][j], adj[j][i]) == float('inf'): un+= 1
    print(un)