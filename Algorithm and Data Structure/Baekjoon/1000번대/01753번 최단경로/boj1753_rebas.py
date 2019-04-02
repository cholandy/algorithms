from heapq import heappush, heappop
from sys import stdin, stdout
input = stdin.readline
print = stdout.write

INF = 1e9
n, m = map(int, input().split())
start = int(input())-1
dist = [INF]*n
a = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    a[u-1].append([v-1, w])

def dijkstra():
    pq = []
    heappush(pq, (0, start))
    dist[start] = 0
    while pq:
        cost, now = heappop(pq)
        if dist[now] < cost:
            continue
        for nxt, ncost in a[now]:
            ncost += cost
            if dist[nxt] > ncost:
                dist[nxt] = ncost
                heappush(pq, (ncost, nxt))

dijkstra()
for i in range(n):
    print("%d\n" % dist[i] if dist[i] != INF else "INF\n")
