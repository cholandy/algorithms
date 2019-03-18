n = int(input())
cost = [[float('inf')]*(n) for i in range(n)]
for B in range(int(input())):
    a,b,c = map(int,input().split())
    cost[a-1][b-1] = min(cost[a-1][b-1], c)
for i in range(n):
    cost[i][i] = 0
for k in range(n):
    for i in range(n):
        for j in range(n):
            if cost[i][j] > cost[i][k]+cost[k][j]:
                cost[i][j] = cost[i][k]+cost[k][j]
for i in cost:
    for j in i:
        if j == float('inf'):
            print(0, end=' ')
        else:
            print(j, end=' ')
    print()