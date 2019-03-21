from collections import deque
while 1:
    l, r, c = map(int,input().split())
    if l == 0: break
    build = []
    for i in range(l):
        build.append([input() for j in range(r)])
        for j in range(r):
            for k in range(c):
                if build[i][j][k] == "S": si, sj, sk = i, j, k
                if build[i][j][k] == "E": ei, ej, ek = i, j, k
        input()
    visit = [[[0]*c for i in range(r)] for j in range(l)]
    visit[si][sj][sk] = 1
    Q = deque()
    Q.append((si,sj,sk))
    while Q:
        i, j, k = Q.popleft()
        for ni,nj,nk in (i-1,j,k), (i+1,j,k), (i,j-1,k), (i,j+1,k), (i,j,k-1), (i,j,k+1):
            if not (0<=ni<l and 0<=nj<r and 0<=nk<c): continue
            if build[ni][nj][nk] == "#" or visit[ni][nj][nk]: continue
            visit[ni][nj][nk] = visit[i][j][k]+1
            Q.append((ni,nj,nk))
            if (ni,nj,nk) == (ei,ej,ek): break
    if visit[ei][ej][ek] == 0: print("Trapped!")
    else: print("Escaped in %d minute(s)." % (visit[ei][ej][ek]-1))