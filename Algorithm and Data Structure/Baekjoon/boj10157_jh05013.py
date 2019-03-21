def get(L, y, x):
    if 0<=y<len(L) and 0<=x<len(L[0]):
        return L[y][x]
    return True

c, r = map(int,input().split())
grid = [[False]*r for i in range(c)]
k = int(input())
if k > c*r:
    print(0)
    exit()

i = 0
j = 0
placed = 0
d = [(0,1), (1,0), (0,-1), (-1,0)]
dind = 0

while 1:
    grid[i][j] = placed+1
    placed+= 1
    if placed == k:
        print(i+1, j+1)
        break
    di, dj = d[dind]
    if get(grid, i+di, j+dj):
        dind = (dind+1)%4
        di, dj = d[dind]
    i+= di
    j+= dj