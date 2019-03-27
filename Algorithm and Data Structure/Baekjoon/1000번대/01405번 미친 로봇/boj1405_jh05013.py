trace = [[0] * 30 for i in range(30)]

def dfs(n, i, j):
    if n == 0: return 1
    p = 0
    for ni, nj, prob in (i+1,j,S), (i-1,j,N), (i,j-1,W), (i,j+1,E):
        if trace[ni][nj]: continue
        trace[ni][nj] = 1
        p+= prob/100 * dfs(n-1, ni, nj)
        trace[ni][nj] = 0
    return p

n, E, W, S, N = map(int,input().split())
trace[0][0] = 1
print(dfs(n, 0, 0))