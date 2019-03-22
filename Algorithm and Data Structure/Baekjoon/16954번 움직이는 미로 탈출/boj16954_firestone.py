import sys;sys.stdin=open('Baekjoon\\16954번 움직이는 미로 탈출\\input.txt','r')
chess=[input() for _ in range(8)]
grid=[[0]*8 for _ in range(8)]
grid[7][0]=1
for t in range(8):
    for i in range(8-t):
        for j in range(8):
            if chess[i][j]=='#':grid[i][j]=0
    torf=[[0]*8 for _ in range(8)]
    for i in range(8):
        for j in range(8):
            for x in [-1,0,1]:
                for y in [-1,0,1]:
                    if 0<=i+x<8 and 0<=j+y<8 and grid[i+x][j+y]:torf[i+x][j+y]=1
    for i in range(8-t):
        for j in range(8):
            if chess[i][j]=='#':torf[i][j]=0
    grid=torf
print(1 if sum(map(sum,grid)) else 0)