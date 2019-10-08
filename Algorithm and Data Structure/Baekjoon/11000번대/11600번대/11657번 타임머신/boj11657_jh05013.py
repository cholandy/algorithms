from sys import setrecursionlimit as SRL, stdin
SRL(550000)
input = stdin.readline

def BellmanFord(n, adj, source):
    dist = [float('inf')]*(n+1)
    dist[source] = 0
    for i in range(n-1):
        for u in range(1, n+1):
            for v, c in adj[u]:
                dist[v] = min(dist[v], dist[u]+c)
    for u in range(1, n+1):
        for v, c in adj[u]:
            if dist[u]+c < dist[v]:
                return False
    return dist

n, m = map(int,input().split())
adj = [[] for i in range(n+1)]
for i in range(m):
    a, b, c = map(int,input().split())
    adj[a].append((b,c))
res = BellmanFord(n, adj, 1)
if not res:
    print(-1)
else:
    for i in range(2,n+1):
        print(res[i] if res[i] != float('inf') else -1)