import sys; sys.stdin=open('input.txt','r')

R,C,T = map(int, input().split())

first, second = 0, 0
home = []
for i in range(R):
    a = list(map(int, input().split()))

    for j in range(C):
        if a[j] == -1:
            if first ==0:
                first=(i,j)
            elif first:
                second=(i,j)
    home.append(a)

# spread 부분은 rebas님의 코드를 참고하였습니다.
def spread():
    global home
    temp = [ [0 for _ in range(C)]  for q in range(R) ] 
    for x in range(R):
        for y in range(C):
            if home[x][y]>4:
                p = home[x][y]//5
                for dx, dy in (0,1),(0,-1),(1,0),(-1,0):
                    nx,ny = x+dx, y+dy 
                    if -1<nx<R and -1<ny<C and home[nx][ny] !=-1:
                        temp[nx][ny]+=p
                        home[x][y]-=p
    for x in range(R):
        for y in range(C):
            home[x][y] += temp[x][y]
# spread 부분은 rebas님의 코드를 참고하였습니다.

def wind1():
    global home
    sx,sy = first[0]-1, first[1] 
    home[sx][sy]=0
    while 1:
        nx, ny = sx-1, sy
        if nx>-1:
            home[sx][sy]=home[nx][ny]
            home[nx][ny]==0
            sx,sy=nx,ny
        else:
            break
    while 1:
        nx, ny = sx, sy+1
        if C>ny:
            home[sx][sy]=home[nx][ny]
            home[nx][ny]==0
            sx,sy=nx,ny
        else:
            break
    while 1:
        nx, ny = sx+1, sy
        if nx<first[0]+1:
            home[sx][sy]=home[nx][ny]
            home[nx][ny]==0
            sx,sy=nx,ny
        else:
            break
    while 1:
        nx, ny = sx, sy-1
        if 0<ny:
            home[sx][sy]=home[nx][ny]
            home[nx][ny]==0
            sx,sy=nx,ny
            if ny==1:
                home[nx][ny]=0
        else:
            break 
    return

def wind2():
    global home
    sx, sy = second[0]+1, second[1]
    home[sx][sy]=0
    while 1:
        nx, ny = sx+1, sy
        if nx<R:
            home[sx][sy]=home[nx][ny]
            home[nx][ny]==0
            sx,sy=nx,ny
        else:
            break
    while 1:
        nx, ny = sx, sy+1
        if ny<C:
            home[sx][sy]=home[nx][ny]
            home[nx][ny]==0
            sx,sy=nx,ny
        else:
            break
    while 1:
        nx, ny = sx-1, sy
        if nx > second[0]-1:
            home[sx][sy]=home[nx][ny]
            home[nx][ny]==0
            sx,sy=nx,ny
        else:
            break
    while 1:
        nx, ny = sx, sy-1
        if 0<ny:
            home[sx][sy]=home[nx][ny]
            home[nx][ny]==0
            sx,sy=nx,ny
            if ny==1:
                home[nx][ny]=0
        else:
            break
    return
# print('This is original')
# [print(*i) for i in home]
# print()

while T:
    spread()
    # print(f'Spread {T}')
    # [print(*i) for i in home]
    # print()
    wind1()
    wind2()
    T-=1

print(sum(map(sum, home)) +2)

