U,D,L,R,F,B = 0,0,0,0,0,0
n, m, y, x, k = map(int,input().split())
grid = [list(map(int,input().split())) for i in range(n)]
for move in map(int,input().split()):
    if move == 1:
        if x == m-1: continue
        U,D,L,R,F,B,x,y = L,R,D,U,F,B,x+1,y
    elif move == 2:
        if x == 0: continue
        U,D,L,R,F,B,x,y = R,L,U,D,F,B,x-1,y
    elif move == 3:
        if y == 0: continue
        U,D,L,R,F,B,x,y = B,F,L,R,U,D,x,y-1
    elif move == 4:
        if y == n-1: continue
        U,D,L,R,F,B,x,y = F,B,L,R,D,U,x,y+1    
    if not grid[y][x]: grid[y][x] = D
    else: grid[y][x], D = 0, grid[y][x]
    print(U)