def get(L, i, j):
    if 0<=i<len(L) and 0<=j<len(L[0]): return L[i][j]
    return ' '

def infect(L, i, j, visit, color):
    Q = deque()
    visit[i][j] = True
    Q.append((i,j))
    while len(Q):
        i, j = Q.popleft()
        for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
            if get(L, ni, nj) in color and not visit[ni][nj]:
                visit[ni][nj] = True
                Q.append((ni,nj))

from collections import deque
def bfs(L, blind):
    res = 0
    visit = [[False]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            if visit[i][j]: continue
            res+= 1
            if blind and L[i][j] != "B": color = "RG"
            else: color = L[i][j]
            infect(L, i, j, visit, color)
    return res

n = int(input())
grid = [input() for i in range(n)]
print(bfs(grid, False), bfs(grid, True))