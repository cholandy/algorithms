def catch(j):
    for i in range(n):
        if not grid[i][j]: continue
        z = grid[i][j][0]
        grid[i][j] = None
        return z
    return 0

def move(i, j, s, d):
    if d == 1 or d == 2:
        di = -1 if d == 1 else 1
        if (i,di) in colcyc: movind = colcyc.index((i,di))
        else: movind = colcyc.index((i,-di))
        ni, ndi = colcyc[(movind+s) % len(colcyc)]
        return ni, j, (1 if ndi == -1 else 2)
    else:
        dj = 1 if d == 3 else -1
        if (j,dj) in rowcyc: movind = rowcyc.index((j,dj))
        else: movind = rowcyc.index((j,-dj))
        nj, ndj = rowcyc[(movind+s) % len(rowcyc)]
        return i, nj, (3 if ndj == 1 else 4)

def move_sharks(grid):
    new = [[[] for j in range(m)] for i in range(n)]
    for i in range(n):
        for j in range(m):
            if not grid[i][j]: continue
            z, s, d = grid[i][j]
            ni, nj, nd = move(i, j, s, d)
            new[ni][nj].append((z, s, nd))
    return [[(max(L) if L else None) for L in row] for row in new]

n, m, S = map(int,input().split())
grid = [[None]*m for i in range(n)]
for i in range(S):
    r, c, s, d, z= map(int,input().split())
    grid[r-1][c-1] = (z, s, d) # size, speed, direction
rowcyc = [(j,1) for j in range(m-1)] + [(j,-1) for j in range(m-1,0,-1)]
colcyc = [(i,1) for i in range(n-1)] + [(i,-1) for i in range(n-1,0,-1)]

ans = 0
for j in range(m):
    ans+= catch(j)
    grid = move_sharks(grid)
print(ans)