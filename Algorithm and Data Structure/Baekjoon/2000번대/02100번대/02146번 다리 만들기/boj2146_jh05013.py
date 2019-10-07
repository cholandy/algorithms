def get(L, i, j):
    if 0<=i<len(L) and 0<=j<len(L[0]): return L[i][j]
    return 0

from collections import deque
def infect(i, j):
    used = [(i,j)]
    Q = deque(); Q.append((i,j))
    grid[i][j] = 0
    while len(Q):
        i, j = Q.popleft()
        for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
            if not get(grid, ni, nj): continue
            grid[ni][nj] = 0
            Q.append((ni,nj))
            used.append((ni,nj))
    return used

def dist(i, j):
    res = 99999
    for x1, y1 in tiles[i]:
        for x2, y2 in tiles[j]:
            res = min(res, abs(x2-x1)+abs(y2-y1)-1)
    return res

n = int(input())
grid = [list(map(int,input().split())) for i in range(n)]
tiles = []

for i in range(n):
    for j in range(n):
        if grid[i][j]:
            island = infect(i, j)
            tiles.append(island)
T = len(tiles)
print(min(dist(i,j) for i in range(T) for j in range(i+1, T)))