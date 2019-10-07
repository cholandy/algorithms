from collections import deque

def get(L, i, j):
    if 0<=i<len(L) and 0<=j<len(L[0]): return L[i][j]
    return -1

def melt(grid):
    C = set()
    visit = [[False]*len(grid[0]) for i in range(len(grid))]
    Q = deque(); Q.append((0,0)); visit[0][0] = True
    while len(Q):
        i, j = Q.popleft()
        for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
            cheese = get(grid, ni, nj)
            if cheese == -1: continue
            elif cheese == 0:
                if visit[ni][nj]: continue
                visit[ni][nj] = True
                Q.append((ni,nj))
            else: C.add((ni,nj))
    for pos in C: grid[pos[0]][pos[1]] = 0
    return len(C)

r, c = map(int,input().split())
grid = [list(map(int,input().split())) for i in range(r)]
prevm = 0
i = 0
while 1:
    m = melt(grid)
    if m == 0:
        print(i)
        print(prevm)
        break
    prevm = m
    i+= 1
