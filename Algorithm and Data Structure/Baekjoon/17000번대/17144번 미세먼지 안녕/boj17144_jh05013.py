n, m, T = map(int,input().split())
grid = [list(map(int,input().split())) for i in range(n)]
for ci in range(n):
    if grid[ci][0] == -1: break

upper = [(ci,j) for j in range(1,m)] + [(i,m-1) for i in range(ci-1,0,-1)] +\
    [(0,j) for j in range(m-1,0,-1)] + [(i,0) for i in range(ci)]
lower = [(ci+1,j) for j in range(1,m)] + [(i,m-1) for i in range(ci+2,n-1)] +\
    [(n-1,j) for j in range(m-1,0,-1)] + [(i,0) for i in range(n-1,ci+1,-1)]
upper.reverse()
lower.reverse()

def wind(path):
    for (i1,j1),(i2,j2) in zip(path, path[1:]):
        grid[i1][j1] = grid[i2][j2]
    i0, j0 = path[-1]
    grid[i0][j0] = 0

# ci = air cleaner index
for TIME in range(T):
    # dirt move
    delta = [[0]*m for i in range(n)]
    for i in range(n):
        for j in range(m):
            am = grid[i][j]//5
            if am == -1: continue
            for ni,nj in (i-1,j),(i+1,j),(i,j-1),(i,j+1):
                if not (0<=ni<n and 0<=nj<m and grid[ni][nj] != -1): continue
                delta[ni][nj]+= am
                grid[i][j]-= am
    for i in range(n):
        for j in range(m): grid[i][j]+= delta[i][j]
 
    # wind
    wind(upper)
    wind(lower)
print(sum(map(sum, grid))+2)