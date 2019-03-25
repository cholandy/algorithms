from sys import stdin
from collections import deque
input = stdin.readline

n, m, k = map(int, input().split())
a = [list(input()) for _ in range(n)]
dist = [[[0]*(k+1) for _ in range(m)] for _ in range(n)]
dx = (-1, 0, 1, 0)
dy = (0, 1, 0, -1)

def bfs():
    q = deque()
    q.append((0, 0, 0))
    dist[0][0][0] = 1
    while q:
        x, y, w = q.popleft()
        if x == n-1 and y == m-1:
            return dist[n-1][m-1][w]
        for i in range(4):
            nx, ny, nw = x+dx[i], y+dy[i], w+1
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if dist[nx][ny][w]:
                continue
            if a[nx][ny] == '0':
                dist[nx][ny][w] = dist[x][y][w] + 1
                q.append((nx, ny, w))
            if a[nx][ny] == '1' and nw <= k:
                dist[nx][ny][nw] = dist[x][y][w] + 1
                q.append((nx, ny, nw))
    return -1

print(bfs())


