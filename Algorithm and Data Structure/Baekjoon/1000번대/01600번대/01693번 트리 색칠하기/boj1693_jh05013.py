from sys import setrecursionlimit as SRL, stdin
input = stdin.readline
#range = xrange

n = int(input())
MAXC = 18
adj = [[] for i in range(n+1)]
tadj = [[] for i in range(n+1)]
for i in range(n-1):
    a, b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)
    
from collections import deque
Q = deque(); Q.append(1)
visit = [False]*(n+1); visit[1] = True
order = []
while len(Q):
    p = Q.popleft()
    for q in adj[p]:
        if visit[q]: continue
        visit[q] = True
        tadj[p].append(q)
        Q.append(q)
    order.append(p)

opt = [[float('inf')]*MAXC for i in range(n+1)]
for p in reversed(order):
    if not tadj[p]:
        for c in range(1, MAXC): opt[p][c] = c
        continue
    for c in range(1, MAXC):
        res = c
        for q in tadj[p]:
            res+= min(opt[q][j] for j in range(1, MAXC) if j != c)
        opt[p][c] = res
print(min(opt[1]))