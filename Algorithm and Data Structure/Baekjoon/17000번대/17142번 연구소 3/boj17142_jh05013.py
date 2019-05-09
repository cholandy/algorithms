from itertools import combinations
from collections import deque

def infect(C):
    vis = [[-1]*n for i in range(n)]
    Q = deque(C)
    visited = 0
    for i,j in C: vis[i][j] = 0
    while Q:
        i,j = Q.popleft()
        for ni,nj in (i-1,j),(i+1,j),(i,j-1),(i,j+1):
            if not (0<=ni<n and 0<=nj<n) or grid[ni][nj] == 1 or vis[ni][nj] != -1: continue
            vis[ni][nj] = vis[i][j]+1
            if grid[ni][nj] == 0: visited+= 1
            Q.append((ni,nj))
    if visited != zero: return 99999
    return max([0]+[vis[i][j] for i in range(n) for j in range(n) if grid[i][j] == 0])

n, m = map(int,input().split())
grid = [list(map(int,input().split())) for i in range(n)]
zero = 0
twos = []
for i in range(n):
    for j in range(n):
        if grid[i][j] == 0: zero+= 1
        if grid[i][j] == 2: twos.append((i,j))
ans = min(infect(C) for C in combinations(twos, m))
print(ans if ans < 99999 else -1)