from collections import deque

def move(x, y, z):
    if x < 0 or x >= n or y < 0 or y >= n:
        return False
    if dist[x][y][z] == '*':
        return False
    return True

def bfs():
    while q:
        x, y, z = q.popleft()
        if x == ex and y == ey:
            print(dist[x][y][z])
            return
        nx, ny = x+dx[z], y+dy[z]
        while move(nx, ny, z) and a[nx][ny] == '.':
            nx, ny = nx+dx[z], ny+dy[z]
        if move(nx, ny, z) and a[nx][ny] == '!':
            dist[nx][ny][z] = dist[x][y][z]
            q.append((nx, ny, z))
            k = 2 if z < 2 else 0
            for i in range(k, k+2):
                if dist[nx][ny][i] == -1:
                    dist[nx][ny][i] = dist[x][y][z]+1
                    q.append((nx, ny, i))

ex, ey = 0, 0
dx, dy = (-1, 1, 0, 0), (0, 0, -1, 1)
n = int(input())
a = [list(input().strip()) for _ in range(n)]
dist = [[[-1]*4 for _ in range(n)] for _ in range(n)]
q = deque()
for i in range(n):
    for j in range(n):
        if a[i][j] == '#':
            if not q:
                for k in range(4):
                    q.append((i, j, k))
                    dist[i][j][k] = 0
            else:
                ex, ey = i, j
            a[i][j] = '!'
bfs()


