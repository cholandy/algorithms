dy = [-1,0,1,0]
dx = [0,1,0,-1]
n, m = map(int,input().split())
r, c, d = map(int,input().split())
grid = [list(map(int,input().split())) for i in range(n)]
clean = 0

def get(L, y, x):
    if 0<=y<len(L) and 0<=x<len(L[0]):
        return L[y][x]
    return 1

turned = 0
while 1:
    if turned == 4:
        turned = 0
        if get(grid, r-dy[d], c-dx[d]) == 1:
            break
        r-= dy[d]
        c-= dx[d]
        continue
    if grid[r][c] == 0:
        grid[r][c] = 2
        clean+= 1
    nextd = (d-1)%4
    if get(grid, r+dy[nextd], c+dx[nextd]) == 0:
        d = nextd
        r+= dy[d]
        c+= dx[d]
        turned = 0
        continue
    else:
        d = nextd
        turned+= 1

print(clean)