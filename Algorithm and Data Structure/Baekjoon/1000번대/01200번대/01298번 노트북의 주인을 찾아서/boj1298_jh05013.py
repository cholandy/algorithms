__import__('sys').setrecursionlimit(123123)
from collections import deque
XRAW = __import__('sys').stdin.read().split()
XIN = iter(XRAW)
INP = lambda: int(next(XIN))

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

n, m = INP(), INP()
adj = [[] for i in range(n+1)]
for i in range(m):
    a, b = INP(), INP()
    adj[a].append(b)
print(HopcroftKarp(n, n, adj))