def pop(si, sj):
    if grid[si][sj] == '.': return False
    vis = {(si, sj)}
    stack = [(si, sj)]
    while stack:
        i, j = stack.pop()
        for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
            if (ni,nj) in vis: continue
            if 0<=ni<12 and 0<=nj<6 and grid[ni][nj] == grid[si][sj]:
                stack.append((ni,nj)) 
                vis.add((ni,nj))
    if len(vis) >= 4:
        for i, j in vis: 
            grid[i][j] = '.'
        return True
    return False

def puyo():
    return sum(pop(i, j) for i in range(12) for j in range(6))

def drop(j):
    pi = 11
    for i in range(11, -1, -1):
        if grid[i][j] != '.':
            grid[i][j], grid[pi][j] = '.', grid[i][j]
            pi-= 1

grid = [list(input()) for i in range(12)]
for CYCLE in range(72):
    if not puyo(): 
        print(CYCLE) 
        break
    for j in range(6): 
        drop(j)