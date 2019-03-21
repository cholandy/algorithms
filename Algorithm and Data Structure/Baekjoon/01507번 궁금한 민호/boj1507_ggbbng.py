import sys


N = int(input())
adj = [[int(x) for x in input().split()] for _ in range(N)]

removed = 0
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        for k in range(N):
            if k == i or k == j:
                continue
            if adj[i][k] + adj[k][j] == adj[i][j]:
                removed += adj[i][j]
                break
            if adj[i][k] + adj[k][j] < adj[i][j]:
                print(-1)
                sys.exit()

print((sum([sum(adj[i]) for i in range(N)]) - removed) // 2)
