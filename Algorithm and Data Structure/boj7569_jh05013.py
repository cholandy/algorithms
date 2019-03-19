from sys import stdin
input = stdin.readline
from collections import deque

def get(L, z, y, x):
    if 0<=x<len(L[0][0]) and 0<=y<len(L[0]) and 0<=z<len(L):
        return L[z][y][x]
    return -1

m, n, h = map(int,input().split())
grid = [[list(map(int,input().split())) for i in range(n)] for j in range(h)]
Q = deque()
target = 0
day = 0
for i in range(h):
    for j in range(n):
        for k in range(m):
            if grid[i][j][k] == 0: target+= 1
            elif grid[i][j][k] == 1: Q.append((0, i, j, k))
while Q:
    day, i, j, k = Q.popleft()
    for newi, newj, newk in (i-1,j,k),(i+1,j,k),(i,j-1,k),(i,j+1,k),(i,j,k-1),(i,j,k+1):
        if get(grid, newi, newj, newk) == 0:
            grid[newi][newj][newk] = 1
            target-= 1
            Q.append((day+1, newi, newj, newk))
if target != 0:
    print(-1)
else:
    print(day)