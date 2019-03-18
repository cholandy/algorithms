n = int(input())
grid = [[-1]*101 for i in range(101)]
for i in range(n):
    x, y, w, h = map(int,input().split())
    for j in range(x, x+w):
        for k in range(y, y+h): grid[j][k] = i
for i in range(n):
    print(sum(row.count(i) for row in grid))