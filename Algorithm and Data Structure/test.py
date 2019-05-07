import sys; sys.stdin=open('input.txt','r')
from collections import deque 

N,M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
ans = float('inf')
def print_grid(grid):
    return [print(*i) for i in grid]

def checkblock(grid):
    cnt = 0
    check = [[0]*N for i in range(N)]
    for i in range(N):
        for j in range(N):
            if grid[i][j] in [0,2] and check[i][j]==0:
                cnt+=1
                q = deque()
                q.append((i,j))
                check[i][j]=1
                while q:
                    x,y = q.popleft()
                    for dx,dy in (1,0), (-1,0), (0,1), (0,-1):
                        nx,ny = x+dx, y+dy
                        if 0<=nx<N and 0<=ny<N and grid[nx][ny]!=1 and check[nx][ny]!=1:
                            check[nx][ny]=1
                            q.append((nx,ny))
    return cnt 
# print_grid(grid)

if checkblock(grid) > M:
    print(-1);exit()

