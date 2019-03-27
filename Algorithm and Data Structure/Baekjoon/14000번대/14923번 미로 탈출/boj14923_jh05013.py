n, m = map(int,input().split())
si, sj = map(int,input().split())
ei, ej = map(int,input().split())
si-=1; sj-=1; ei-=1; ej-= 1
grid = [list(map(int,input().split())) for i in range(n)]
visit = [[[float('inf')]*m for i in range(n)] for j in range(2)]

Q = []
visit[0][si][sj] = 0; Q.append((si,sj,0))
while Q:
    new = []
    for i,j,k in Q:
        for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
            if not (0<=ni<n and 0<=nj<m): continue
            nk = k+grid[ni][nj]
            if nk == 2: continue
            if visit[nk][ni][nj] != float('inf'): continue
            visit[nk][ni][nj] = visit[k][i][j]+1; new.append((ni,nj,nk))
    Q = new
res = min(visit[0][ei][ej], visit[1][ei][ej])
if res == float('inf'): print(-1)
else: print(res)