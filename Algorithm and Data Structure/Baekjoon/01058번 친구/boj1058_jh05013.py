def Floyd(n, cost):
    for i in range(n): cost[i][i] = 0
    for k in range(n):
        for i in range(n):
            for j in range(n): cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])

n = int(input())
fr = [[(1 if c=="Y" else float('inf')) for c in input()] for i in range(n)]
Floyd(n, fr)
print(max(sum(0<x<=2 for x in row) for row in fr))