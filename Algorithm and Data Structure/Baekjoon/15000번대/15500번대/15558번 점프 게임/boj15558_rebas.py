from collections import deque
from sys import stdin
input = stdin.readline

def bfs():
    q = deque()
    q.append((0, 0))
    for i in range(n):
        for j in range(len(q)):
            x, y = q.popleft()
            for nx, ny in (x, y-1), (x, y+1), (not x, y+k):
                if ny >= n:
                    print(1)
                    return
                if ny > i and not check[nx][ny] and a[nx][ny] == '1':
                    q.append((nx, ny))
                    check[nx][ny] = True
    print(0)

n, k = map(int, input().split())
a = [list(input().strip()) for _ in range(2)]
check = [[False]*n for _ in range(2)]
bfs()


