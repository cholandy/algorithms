from heapq import heappush, heappop

import sys;sys.stdin=open('input1.txt','r')
INF = 1e9
n = int(input())
m = int(input())
dist = [INF]*n
a = [[] for _ in range(n)]
for i in range(m):
    u, v, w = map(int, input().split())
    a[u-1].append([v-1, w])
depart, arrive = map(int, input().split())

def dijkstra():
    pq = []
    heappush(pq, (0, depart-1))
    dist[depart-1] = 0
    while pq:
        cost, now = heappop(pq)
        if dist[now] < cost:
            continue
        for nxt, ncost in a[now]:
            ncost += cost
            if dist[nxt] > ncost:
                dist[nxt] = ncost
                heappush(pq, (ncost, nxt))
    print(dist[arrive-1])

dijkstra()