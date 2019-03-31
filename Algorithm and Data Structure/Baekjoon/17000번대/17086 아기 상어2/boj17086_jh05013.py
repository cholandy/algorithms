MIS = lambda: map(int,input().split())
from collections import deque

n, m = MIS()
grid = [list(MIS()) for i in range(n)]
Q = deque([(i,j) for i in range(n) for j in range(m) if grid[i][j] == 1])
while Q:
    i, j = Q.popleft()
    for ni,nj in (i-1,j-1),(i-1,j),(i-1,j+1),(i,j-1),(i,j+1),(i+1,j-1),(i+1,j),(i+1,j+1):
        if not (0<=ni<n and 0<=nj<m) or grid[ni][nj]: continue
        grid[ni][nj] = grid[i][j]+1
        Q.append((ni,nj))
print(max(map(max,grid))-1)