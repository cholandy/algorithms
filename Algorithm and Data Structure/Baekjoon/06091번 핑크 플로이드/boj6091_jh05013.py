__import__('sys').setrecursionlimit(123123)
def MST(n, edges, sort=True):
    parent = list(range(n+1))
    def union(x, y): parent[find(x)] = find(y)
    def find(x):
        if parent[x] != x: parent[x] = find(parent[x])
        return parent[x]
    
    if sort: edges.sort()
    cost = 0; MST = []
    for e in edges:
        c, a, b = e
        if find(a) != find(b): cost+= c; union(a, b); MST.append(e)
    if len(MST) < n-1: return float('inf'), []
    return MST

n = int(input())
edge = []
for i in range(n-1):
    cost = list(map(int,input().split()))
    for j in range(n-i-1): edge.append((cost[j], i, i+j+1))
adj = [[] for i in range(n+1)]
for c, a, b in MST(n, edge): adj[a+1].append(b+1); adj[b+1].append(a+1)
for L in adj[1:]: print(len(L), *sorted(L))