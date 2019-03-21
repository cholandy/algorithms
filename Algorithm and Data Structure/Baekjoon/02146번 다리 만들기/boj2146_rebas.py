from sys import stdin
from collections import deque
input = stdin.readline

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
check = [[False]*n for _ in range(n)]
q = deque()
dx = (-1, 0, 1, 0)
dy = (0, 1, 0, -1)

def bfs():
    ans = 1e9
    while q:
        x, y, d = q.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if check[nx][ny] is True:
                continue
            if a[nx][ny] == 1:
                q.appendleft((nx, ny, d))
                if a[x][y] == 0 and ans > d:
                    ans = d
            else:
                if a[x][y] == 1:
                    q.append((nx, ny, 1))
                else:
                    q.append((nx, ny, d+1))
            check[nx][ny] = True
    return ans

def init():
    for i in range(n):
        for j in range(n):
            if init and a[i][j] == 1:
                q.append((i, j, 0))
                check[i][j] = True
                return

init()
print(bfs())