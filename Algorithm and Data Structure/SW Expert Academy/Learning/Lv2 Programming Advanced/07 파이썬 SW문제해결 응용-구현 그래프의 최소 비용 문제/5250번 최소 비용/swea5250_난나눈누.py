import sys;sys.stdin=open('input1.txt','r')
from collections import deque
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def wall(x,y):
    if 0<=x<N and 0<=y<N: return True
    return False

for tc in range(int(input())):
    N=int(input())
    grid=[list(map(int,input().split())) for _ in range(N)]
    # dp=[[0]*N for _ in range(N)]
    visited=[[0]*N for _ in range(N)]
    visited[0][0]=1
    Q=deque()
    Q.append([0,0])
    
    while Q:
        i,j=Q.popleft()       
        for k in range(4):
            idx,idy=i+dx[k],j+dy[k]
            if wall(idx,idy):
                gas=1
                if grid[idx][idy]>grid[i][j]:
                    gas+=grid[idx][idy]-grid[i][j]
                if not visited[idx][idy] or visited[i][j]+gas<visited[idx][idy]:
                    Q.append([idx,idy])
                    visited[idx][idy]=visited[i][j]+gas
  
    print(f"#{tc+1} {visited[N-1][N-1]-1}")

