input = __import__('sys').stdin.readline
from collections import deque

n = int(input())
bfsorder = []

adj = [[] for i in range(n+1)]
tadj = [[] for i in range(n+1)]
for i in range(n-1):
    a, b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)

Q = deque([1])
vis = [False]*(n+1)
vis[1] = True
while Q:
    p = Q.popleft()
    bfsorder.append(p)
    for q in adj[p]:
        if vis[q]: continue
        vis[q] = True
        tadj[p].append(q)
        Q.append(q)

dp0 = [None]*(n+1) # i is early adopter
dp1 = [None]*(n+1) # i is not early adopter
for i in reversed(bfsorder):
    dp0[i] = sum(dp1[v] for v in tadj[i])
    dp1[i] = 1 + sum(min(dp0[v], dp1[v]) for v in tadj[i])
print(min(dp0[1], dp1[1]))