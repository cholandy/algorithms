for _ in range(int(input())):
    n = int(input())
    sx, sy = map(int, input().split())
    ex, ey = map(int, input().split())
    d = [[-1 for _ in range(n)] for i in range(n)]
    q = list()
    def f(x, y, z):
        if x >= 0 and x < n and y >= 0 and y < n and d[x][y] < 0:
            d[x][y] = z
            q.append((x, y, z))
    f(sx, sy, 0)
    while q and d[ex][ey] < 0:
        x, y, z = q.pop(0)
        f(x + 2, y + 1, z + 1)
        f(x + 2, y - 1, z + 1)
        f(x + 1, y + 2, z + 1)
        f(x + 1, y - 2, z + 1)
        f(x - 1, y + 2, z + 1)
        f(x - 1, y - 2, z + 1)
        f(x - 2, y + 1, z + 1)
        f(x - 2, y - 1, z + 1)
    print(d[ex][ey])