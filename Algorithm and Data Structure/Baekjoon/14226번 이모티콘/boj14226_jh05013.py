import heapq
def dijkstra(adj, source):
    n = len(adj)-1; dist = [float('inf')]*(n+1)
    dist[source] = 0; PQ = [(0, source)]
    while PQ:
        d, u = heapq.heappop(PQ)
        if dist[u] != d: continue
        for v, c in adj[u]:
            if dist[v] > d+c: dist[v] = d+c; heapq.heappush(PQ, (d+c, v))
    return dist

n = int(input())
adj = [[] for i in range(2*n)]
for i in range(1, 2*n):
    adj[i].append((i-1, 1))
    dist = 2
    for j in range(i+i, 2*n, i):
        adj[i].append((j, dist))
        dist+= 1
print(dijkstra(adj, 1)[n])