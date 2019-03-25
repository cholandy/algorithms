from collections import deque
from sys import stdin
input = stdin.readline

def bfs(sx, sy):
    dist = [[-1]*(w+2) for _ in range(h+2)]
    q = deque()
    q.append((sx, sy))
    dist[sx][sy] = 0
    while q:
        x, y = q.popleft()
        for dx, dy in (-1,0), (1,0), (0,-1), (0,1):
            nx, ny = x+dx, y+dy
            if nx < 0 or nx > h+1 or ny < 0 or ny > w+1:
                continue
            if dist[nx][ny] >= 0 or a[nx][ny] == '*':
                continue
            if a[nx][ny] == '.':
                dist[nx][ny] = dist[x][y]
                q.appendleft((nx, ny))
            elif a[nx][ny] == '#':
                dist[nx][ny] = dist[x][y]+1
                q.append((nx, ny))
    return dist

for _ in range(int(input())):
    h, w = map(int, input().split())
    a = ['.'*(w+2)]
    for _ in range(h):
        a.append(list('.'+input().strip()+'.'))
    a.append(list('.'*(w+2)))
    dq = deque()
    for i in range(h+2):
        for j in range(w+2):
            if a[i][j] == '$':
                a[i][j] = '.'
                dq.append((i, j))
    sx, sy = dq.pop()
    d1 = bfs(sx, sy)
    sx, sy = dq.pop()
    d2 = bfs(sx, sy)
    d3 = bfs(0, 0)
    ans = 1e9
    for i in range(h+2):
        for j in range(w+2):
            if a[i][j] == '*':
                continue
            k = d1[i][j] + d2[i][j] + d3[i][j]
            if a[i][j] == '#':
                k -= 2
            ans = min(ans, k)
    print(ans)


