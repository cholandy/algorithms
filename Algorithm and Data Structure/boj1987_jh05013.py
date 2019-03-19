input = raw_input
range = xrange

def get(L, y, x):
    if 0<=y<len(L) and 0<=x<len(L[0]): return L[y][x]
    return L[0][0]

def dfs(i, j, depth):
    global opt
    opt = max(opt, depth)
    if opt == len(totalph): return
    for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
        c = ord(get(grid, ni, nj))-65
        if visit[c]: continue
        visit[c] = 1
        dfs(ni, nj, depth+1)
        visit[c] = 0

r, c = map(int,input().split())
grid = [input() for i in range(r)]
totalph = set(''.join(grid))
opt = 0
visit = [0]*26
visit[ord(grid[0][0])-65] = 1
dfs(0, 0, 1)
print(opt)