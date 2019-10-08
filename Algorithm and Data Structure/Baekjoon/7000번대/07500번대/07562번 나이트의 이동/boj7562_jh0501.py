def get(L, i, j):
    if 0<=i<len(L) and 0<=j<len(L[0]): return L[i][j]
    return 999

def move(i, j):
    return (i-2,j-1), (i-2,j+1), (i-1,j-2), (i-1,j+2),\
           (i+2,j-1), (i+2,j+1), (i+1,j-2), (i+1,j+2)

from collections import deque
for TEST in range(int(input())):
    l = int(input())
    grid = [[-1]*l for i in range(l)]
    si, sj = map(int,input().split())
    ti, tj = map(int,input().split())
    Q = deque()
    Q.append((si,sj))
    grid[si][sj] = 0
    while 1:
        i, j = Q.popleft()
        if (i,j) == (ti,tj): break
        for ni, nj in move(i,j):
            if get(grid, ni, nj) != -1: continue
            grid[ni][nj] = grid[i][j]+1
            Q.append((ni,nj))
    print(grid[ti][tj])