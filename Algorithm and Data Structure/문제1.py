import sys;sys.stdin=open('C:\\Users\\student\\Desktop\\asdf\\Algorithm and Data Structure\\input1.txt','r')
from collections import deque
input=__import__('sys').stdin.readline

dx = [-3,-3,-2,-2,2,2,3,3]
dy = [2,-2,3,-3,3,-3,2,-2]

for tc in range(int(input())):
    N=int(input()) # N=판의 크기
    board=[[0]*N for _ in range(N)]
    x,y,tx,ty=map(int,input().split())
    board[tx][ty]=2
    board[x][y]=1
    cnt=0
    Q=deque()
    Q.append((x,y,cnt))
    while Q:
        x,y,cnt=Q.popleft()
        if x==tx and y==ty:break
        for i in range(8):
            nx,ny = x+dx[i],y+dy[i]
            if -1<nx<N+1 and -1<ny<N+1:
                Q.append((nx,ny,cnt+1))

    print(f'#{tc+1} {cnt}')