from collections import deque

def bfs(i, j):
    global sheep, wolf
    q = deque()
    q.append((i, j))
    check[i][j] = True
    o, v = 0, 0
    while q:
        x, y = q.popleft()
        if a[x][y] == 'o':
            o += 1
        if a[x][y] == 'v':
            v += 1
        for dx, dy in (-1,0), (1,0), (0,-1), (0,1):
            nx, ny = x+dx, y+dy
            if nx < 0 or nx >= r or ny < 0 or ny >= c:
                continue
            if not check[nx][ny] and a[nx][ny] != '#':
                q.append((nx, ny))
                check[nx][ny] = True
    if o > v:
        sheep += o
    else:
        wolf += v

r, c = map(int, input().split())
a = [list(input().strip()) for _ in range(r)]
check = [[False]*c for _ in range(r)]
sheep, wolf = 0, 0
for i in range(r):
    for j in range(c):
        if not check[i][j] and a[i][j] != '#':
            bfs(i, j)
print("%d %d" % (sheep, wolf))


