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
            # 1은 벽이니깐 '-'로 바꾼다.
            if grid[i][j]==1:
                tmp[i][j]=0
    return tmp

twos = [(i,j) for i in range(N) for j in range(N) if grid[i][j]==2]


def check(tmp):
    for i in range(N):
        for j in range(N):
            if tmp[i][j]==-1:
                return False
    return True

for starters in combinations(twos, M):
    tmp = grid_copy(grid, starters)
    # print_grid(tmp)
    q=deque()
    for i in starters:
        q.append(i)
    while q:
        x,y = q.popleft()
        for dx,dy in (1,0),(-1,0),(0,1),(0,-1):
            nx,ny=x+dx,y+dy
            if 0<=nx<N and 0<=ny<N and tmp[nx][ny]==-1:
                tmp[nx][ny]=tmp[x][y] + abs(nx-x) + abs(ny-y)
                q.append((nx,ny))
    if check(tmp):
        ans = min(ans, max(map(max, tmp)))
if ans==9999:
    print(-1)
else:
    print(ans)
