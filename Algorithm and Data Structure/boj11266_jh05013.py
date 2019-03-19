from sys import setrecursionlimit as SRL, stdin
SRL(150000)
input = stdin.readline

def biconnected(n, adj):
    parent = [None]*(n+1)
    visited = [False]*(n+1)
    depth = [-1]*(n+1)
    low = [-1]*(n+1)
    res = []
    for i in range(1, n+1):
        if not visited[i]:
            articulation(n, adj, i, 0, parent, visited, depth, low, res)
    return res

def articulation(n, adj, i, d, parent, visited, depth, low, res):
    visited[i] = True
    depth[i] = d
    low[i] = d
    child = 0
    articulate = False
    for j in adj[i]:
        if not visited[j]:
            parent[j] = i
            articulation(n, adj, j, d+1, parent, visited, depth, low, res)
            child+= 1
            if low[j] >= depth[i]: articulate = True
            low[i] = min(low[i], low[j])
        elif j != parent[i]:
            low[i] = min(low[i], depth[j])
    if (parent[i] != None and articulate) or (parent[i] == None and child > 1):
        res.append(i)

v, e = map(int,input().split())
adj = [[] for i in range(v+1)]
for i in range(e):
    a, b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)
bi = biconnected(v, adj)
bi.sort()
print(len(bi))
print(*bi, sep=' ')