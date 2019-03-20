def cyclic(adj):
    def visit(v):
        if visited[v]: return False
        visited[v] = True
        path[v] = True
        for u in adj[v]:
            if path[u] or visit(u): return True
        path[v] = False
        return False
    n = len(adj)
    path = [False]*n
    visited = [False]*n
    return visit(1)

from collections import deque
def bfs(adj, source):
    n = len(adj)
    visited = [False]*n; visited[source] = True
    Q = deque(); Q.append(source)
    while len(Q):
        p = Q.popleft()
        for q in adj[p]:
            if visited[q]: continue
            visited[q] = True
            Q.append(q)
    return visited

from sys import setrecursionlimit as SRL, stdin
SRL(234234)
input = stdin.readline

n = int(input())
adj = [[] for i in range(n+1)]
radj = [[] for i in range(n+1)]
for i in range(1, n):
    room = int(input())
    for j in map(int,input().split()):
        adj[i].append(j)
        radj[j].append(i)

limited = "UNLIMITED" if cyclic(adj) else "LIMITED"
bfs1 = bfs(adj, 1)
bfs2 = bfs(radj, n)
pardon = "PRISON" if any((bfs1[i] and not bfs2[i]) for i in range(1, n+1)) else "PARDON"
print(pardon, limited)