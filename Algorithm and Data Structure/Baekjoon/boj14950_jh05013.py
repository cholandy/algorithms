def Kruskal(n, edges, sort=True):
    def union(x,y):
        xr = find(x); yr = find(y)
        if xr == yr: return
        if rank[xr] < rank[yr]: parent[xr] = yr
        elif rank[xr] > rank[yr]: parent[yr] = xr
        else: parent[yr] = xr; rank[xr]+= 1
    
    def find(x):
        if parent[x] != x: parent[x] = find(parent[x])
        return parent[x]
    
    if sort: edges.sort()
    cost = 0; rank = [0]*(n+1); parent = list(range(n+1)); MST = []
    for e in edges:
        c, a, b = e
        if find(a) != find(b): cost+= c; union(a, b); MST.append(e)
    if len(MST) < n-1: return float('inf')
    return cost

from sys import stdin
input = stdin.readline
v, e, t = map(int,input().split())
edges = []
for i in range(e):
    a, b, c = map(int,input().split())
    edges.append((c,a,b))
cost = Kruskal(v, edges)
print(cost + t*(v-2)*(v-1)//2)