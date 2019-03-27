from sys import setrecursionlimit as SRL
SRL(15000)
from collections import deque
def BFS(ssize, tsize, adj, pairu, pairv, dist):
    Q = deque()
    for u in range(1, ssize+1):
        if pairu[u] == 0: dist[u] = 0; Q.append(u)
        else: dist[u] = float('inf')
    dist[0] = float('inf')
    while len(Q) > 0:
        u = Q.popleft()
        if dist[u] >= dist[0]: continue
        for v in adj[u]:
            if dist[pairv[v]] == float('inf'):
                dist[pairv[v]] = dist[u] + 1
                Q.append(pairv[v])
    return dist[0] != float('inf')

def DFS(ssize, tsize, adj, pairu, pairv, dist, u):
    if u == 0: return True
    for v in adj[u]:
        if dist[pairv[v]] == dist[u] + 1 and DFS(ssize, tsize, adj, pairu, pairv, dist, pairv[v]):
            pairv[v] = u; pairu[u] = v; return True
    dist[u] = float('inf'); return False

def HopcroftKarp(ssize, tsize, adj):
    pairu = [0]*(ssize+1); pairv = [0]*(tsize+1); dist = [-1]*(ssize+1)
    match = 0
    while BFS(ssize, tsize, adj, pairu, pairv, dist):
        for u in range(1, ssize+1):
            if pairu[u] == 0: match+= DFS(ssize, tsize, adj, pairu, pairv, dist, u)
    return match

for TEST in range(int(input())):
    n, m = map(int,input().split())
    grid = [input() for i in range(n)]
    avail = sum(row.count('.') for row in grid)
    ref0 = {}
    ref1 = {}
    for i in range(n):
        for j in range(m):
            if j%2 == 0: ref0[i,j] = len(ref0)+1
            else: ref1[i,j] = len(ref1)+1
    adj = [[] for i in range(len(ref0)+1)]
    for i, j in ref0:
        if grid[i][j] == 'x': continue
        sn = ref0[i,j]
        for ni, nj in (i-1,j-1), (i,j-1), (i+1,j-1), (i-1,j+1), (i,j+1), (i+1,j+1):
            if not (0<=ni<n and 0<=nj<m) or grid[ni][nj] == 'x': continue
            adj[sn].append(ref1[ni,nj])
    print(avail - HopcroftKarp(len(ref0), len(ref1), adj))