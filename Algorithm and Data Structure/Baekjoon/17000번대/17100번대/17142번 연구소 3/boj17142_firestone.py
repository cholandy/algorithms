import sys; sys.stdin=open('input.txt','r')

from collections import deque 
from itertools import combinations 

N,M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
ans = 9999

def print_grid(grid):
    return [print(*i) for i in grid]

def grid_copy(grid, starters):
    tmp=[[-1]*N for _ in range(N)]
    for i in starters:
        x,y = i
        tmp[x][y]=0
    for i in range(N):
        for j in range(N):
            if grid[i][j]==1:
                tmp[i][j]=-2
            elif grid[i][j]==2 and tmp[i][j]:
                tmp[i][j]=-3
    return tmp

twos = [(i,j) for i in range(N) for j in range(N) if grid[i][j]==2]

for starters in combinations(twos, M):
    tmp = grid_copy(grid, starters)
    q=deque()
    for i in starters:
        x,y=i
        q.append((x,y,0))
    while q:
        x,y,d = q.popleft()
        for dx,dy in (1,0),(-1,0),(0,1),(0,-1):
            nx,ny=x+dx,y+dy
            if 0<=nx<N and 0<=ny<N and tmp[nx][ny]==-3:
                tmp[nx][ny]=0
                q.append((nx,ny,d+1))
            if 0<=nx<N and 0<=ny<N and tmp[nx][ny]==-1:
                tmp[nx][ny]=d+1
                q.append((nx,ny,d+1))
    if not any(True for i in range(N) for j in range(N) if tmp[i][j]==-1):
        ans = min(ans, max(map(max, tmp)))

print(ans if ans<9999 else -1)
