import sys; sys.stdin=open('input.txt','r')

R,C,m = map(int, input().split())
sea = [[0]*C for _ in range(R)]
if m==0: print(0);exit()

direc = [0,[-1,0],[1,0],[0,1],[0,-1]]
change = [0,2,1,4,3]

for _ in range(m):
    r,c,s,d,z = map(int, input().split())
    sea[r-1][c-1] = [s,d,z]
    

# [print(*i) for i in sea ]

def fishing(cnt):
    global sea
    for i in range(R):
        if sea[i][cnt]:
            shark = sea[i][cnt][2]
            sea[i][cnt]=0
            return shark
    return 0

def move():
    global sea
    tmp = [ [ [] for _ in range(C) ] for _ in range(R)   ]
    
    for i in range(R):
        for j in range(C):
            if sea[i][j]:
                v=sea[i][j][0]
                x,y = i,j
                while v:
                    dx, dy = direc[sea[i][j][1]]
                    nx, ny = x+dx, y+dy 
                    if -1<nx<R and -1<ny<C:
                        x,y = nx,ny
                        v-=1
                        continue
                    else:
                        sea[i][j][1] = change[sea[i][j][1]]
                tmp[x][y].append(sea[i][j])
                sea[i][j] = 0
    # [print(*i) for i in sea ]
    # [print(*i) for i in tmp ]
    for i in range(R):
        for j in range(C):
            if len(tmp[i][j])>1:
                big = tmp[i][j][0]
                for e in range(len(tmp[i][j])):
                    if tmp[i][j][e][2] > big[2]:
                        big = tmp[i][j][e]
                sea[i][j] = big
            elif len(tmp[i][j])==1:
                sea[i][j] = tmp[i][j][0] 

catch = 0
cnt = -1
while cnt<C-1:
    cnt+=1
    catch += fishing(cnt)
    move()

print(catch)