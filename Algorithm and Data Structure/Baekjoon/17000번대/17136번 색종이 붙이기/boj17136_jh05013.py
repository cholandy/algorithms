import sys;sys.stdin=open('input2.txt','r')

def add(i, j, sz, val):
    for ni in range(i, i+sz):
        for nj in range(j, j+sz): grid[ni][nj]+= val
    paper[sz]+= val

def dfs(i, j):
    if i == 10: return 0
    if j == 10: return dfs(i+1, 0)
    if grid[i][j] == 0: return dfs(i, j+1)
    ans = 9999
    for sz in range(1, 6):
        if i+sz > 10 or j+sz > 10: break
        if any(not grid[ni][nj] for ni in range(i,i+sz) for nj in range(j,j+sz)): break
        if not paper[sz]: continue
        add(i, j, sz, -1)
        ans = min(ans, dfs(i,j+1)+1)
        add(i, j, sz, 1)
    return ans

for tc in range(int(input())):
    grid = [list(map(int,input().split())) for i in range(10)]
    paper = [5]*6
    v = dfs(0,0)
    print("#{}".format(tc+1),end=' ')
    print(v if v != 9999 else -1)