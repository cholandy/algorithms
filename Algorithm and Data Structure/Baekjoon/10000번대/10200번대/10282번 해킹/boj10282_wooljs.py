import sys
from heapq import heappush, heappop
read=lambda:sys.stdin.readline().strip()
write=lambda x:sys.stdout.write(x+"\n")
isinf=lambda x:x>=100000000 
inf = 100000000
T = int(read())
for _ in range(T):
    n, d, c = map(int, read().split())
    G = {i:{"to":set(),"visited":False} for i in range(n)}
    dist = [inf for i in range(n)]
    prev = [-1 for i in range(n)]
    for __ in range(d):
        a, b, s = map(int, read().split())
        G[b-1]["to"].add((s, a-1))

    dist[c-1] = 0
    q = [(0, c-1)]
    while q:
        cur = heappop(q)[1]
        if G[cur]["visited"]:
            continue
        G[cur]["visited"] = True
        for t, nxt in G[cur]["to"]:
            old = dist[nxt] 
            new = dist[cur] + t
            if old > new:
                dist[nxt] = new
                heappush(q, (new, nxt))
    maxd, cnt = -1, 0
    for i in range(n):
        d = dist[i]
        if isinf(d):
            continue
        if d > maxd:
            maxd = d
        cnt += 1
    write(str(cnt)+" "+str(maxd))