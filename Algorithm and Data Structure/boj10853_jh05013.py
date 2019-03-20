from sys import stdin
input = stdin.readline
range = xrange
import heapq
def Dijkstra(n, adj, source):
    dist = [float('inf')]*(n+1); dist[source] = 0
    ways = [0]*(n+1); ways[source] = 1
    PQ = [(0,source)]
    while len(PQ):
        d, u = heapq.heappop(PQ)
        if dist[u] != d: continue
        for v in adj[u]:
            c, mult = adj[u][v]
            if dist[v] > d+c:
                dist[v] = d+c
                heapq.heappush(PQ, (d+c,v))
                ways[v] = min(2, ways[u]*mult)
            elif dist[v] == d+c:
                ways[v]+= ways[u]*mult
                ways[v] = min(2, ways[v])
    return ways

n, m, k = map(int,input().split())
input()
adj = [{} for i in range(n+1)]
for i in range(m):
    a, b, c = map(int,input().split())
    prev, count = adj[a].get(b, (float('inf'),0))
    if prev < c: continue
    elif prev == c: adj[a][b] = (c, count+1); adj[b][a] = (c, count+1)
    else: adj[a][b] = (c, 1); adj[b][a] = (c, 1)
print("yes" if Dijkstra(n, adj, 1)[-1] > 1 else "no")