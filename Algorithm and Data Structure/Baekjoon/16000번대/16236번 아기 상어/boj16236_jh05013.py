from collections import deque
def babyshark(si, sj):
    Q = deque([(si,sj)])
    dist = [[9999]*n for i in range(n)]; dist[si][sj] = 0
    while Q:
        i, j = Q.popleft()
        for ni, nj in (i-1,j), (i+1,j), (i,j-1), (i,j+1):
            if not (0<=ni<n and 0<=nj<n and dist[ni][nj] == 9999): continue
            if grid[ni][nj] > size: continue
            dist[ni][nj] = dist[i][j]+1; Q.append((ni,nj))
    L = [(dist[i][j], i, j) for i in range(n) for j in range(n) if 0 < grid[i][j] < size]
    return min(L + [(9999, 99, 99)])

n = int(input())
grid = [list(map(int,input().split())) for i in range(n)]
size = 2
eat = 0
time = 0
for i in range(n):
    for j in range(n):
        if grid[i][j] == 9: si, sj = i, j; grid[i][j] = 0

while 1:
    t, i, j = babyshark(si, sj)
    if t == 9999: break
    time+= t
    si, sj= i, j; grid[i][j] = 0
    eat+= 1
    if size == eat: size, eat = size+1, 0
print(time)