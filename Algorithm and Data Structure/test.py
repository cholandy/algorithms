import sys;sys.stdin=open('input1.txt','r')
from collections import deque
dx=[0,0,-1,1]
dy=[1,-1,0,0]

for tc in range(int(input())):
    N=int(input())
    grid=[list(map(int,input().split())) for _ in range(N)]
    dp=[[0]*N for _ in range(N)]
    visited=[[False]*N for _ in range(N)]
    visited[0][0]=True
    Q=deque()
    Q.append([0,0,0])
    
    while Q:
        i,j,cnt=Q.pop()
        MIN=float('INF')
        for k in range(4):
            idx,idy=i+dx[k],j+dy[k]
            if 0<=idx<N and 0<=idy<N and grid[idx][idy]<MIN and not visited[idx][idy]:
                MIN=grid[idx][idy]
                nidx,nidy=idx,idy
        # 여기 까지는 주인공에서 위/아래/왼/오 중 가장 작은 값을 가진 인덱스를 뽑아낸 것.
        for k in range(4):
            idx,idy=i+dx[k],j+dy[k]
            if 0<=idx<N and 0<=idy<N and not visited[idx][idy] and grid[idx][idy]==grid[nidx][nidy]:  
                visited[idx][idy]=True
                if grid[idx][idy]-grid[i][j]>0:
                    dp[idx][idy]=grid[idx][idy]-grid[i][j]+cnt+1
                else:
                    dp[idx][idy]=cnt+1
                # if dp[ix][iy]>dp[i][j]:
                #     dp[ix][iy]=dp[i][j]
                Q.append([idx,idy,cnt+1])
    [print(*i) for i in dp]
    print(f"#{tc+1} {dp[N-1][N-1]}")

