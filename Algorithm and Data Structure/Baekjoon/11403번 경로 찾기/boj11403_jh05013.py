n = int(input())
grid = [list(map(int,input().split())) for i in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 0:
                grid[i][j] = grid[i][k]*grid[k][j]

for i in range(n):
    for j in range(n):
        print(grid[i][j], end=' ')
    print()