input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())

n, v1, v2 = MIS()
if v1 == v2: print(0); exit()
adj = [[] for i in range(n+1)]
for i in range(n-1):
    a, b, c = MIS()
    adj[a].append((b,c))
    adj[b].append((a,c))

dist = [-1]*(n+1)
maxd = [-float('inf')]*(n+1)
dist[v1] = 0
stack = [v1]
while stack:
    p = stack.pop()
    for q, c in adj[p]:
        if dist[q] != -1: continue
        dist[q] = dist[p] + c
        maxd[q] = max(maxd[p], c)
        stack.append(q)
print(dist[v2] - maxd[v2])