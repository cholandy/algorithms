from sys import stdin
input = stdin.readline
n, m = map(int,input().split())
adj = [[] for i in range(n)]
for i in range(m):
    a, b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)
dp = [-float('inf')]*(n)
for v in sorted(range(n), key = lambda i: len(adj[i])):
    poss = [1] + [dp[u]+1 for u in adj[v] if len(adj[u]) < len(adj[v])]
    dp[v] = max(poss)
print(max(dp))