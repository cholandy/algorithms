grid = [input() for i in range(8)]
if grid[7][0] == '#': print(0); exit()

def get(L, i, j):
    if 0<=i<len(L) and 0<=j<len(L): return L[i][j]
    return '.'

def neigh(i,j,t):
    for ni,nj in (i,j),(i-1,j-1),(i-1,j),(i-1,j+1),(i,j-1),(i,j+1),(i+1,j-1),(i+1,j),(i+1,j+1):
        if not (0<=ni<8 and 0<=nj<8): continue
        if get(grid, ni-t, nj) == '#' or get(grid, ni-t-1, nj) == '#': continue
        yield (ni,nj,t+1)

stack = [(7,0,0)]
vis = {(7,0,0)}
while stack:
    i,j,t = stack.pop()
    for ni,nj,nt in neigh(i,j,t):
        if nt == 8: print(1); exit()
        if (ni,nj,nt) in vis: continue
        vis.add((ni,nj,nt)); stack.append((ni,nj,nt))
print(0)