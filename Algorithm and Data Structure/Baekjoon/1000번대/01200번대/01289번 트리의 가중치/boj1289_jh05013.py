from sys import stdin
input = stdin.readline

from sys import stdin
input = stdin.readline
n = int(input())
adj = [[] for i in range(n+1)]
tadj = [[] for i in range(n+1)] # rooted at 1
for i in range(n-1):
    a, b, c = map(int,input().split())
    adj[a].append((b,c))
    adj[b].append((a,c))
parent = [-1]*(n+1)
parent[1] = -2
bfsorder = [] # the order of bfs

from collections import deque
Q = deque()
Q.appendleft(1)
while len(Q):
    p = Q.pop()
    bfsorder.append(p)
    for son,c in adj[p]:
        if parent[son] != -1: continue
        parent[son] = p
        tadj[p].append((son,c))
        Q.appendleft(son)

def pairwise(L):
    s = sum(L)**2
    for i in L: s-= i**2
    return s//2

MOD = 10**9+7
endsum = [0]*(n+1) # ascends to v and stops
midsum = [0]*(n+1) # ascends to v and descends
for p in reversed(bfsorder):
    if not tadj[p]: continue
    routes = [endsum[q]*c+c for q,c in tadj[p]]
    endsum[p] = sum(routes) % MOD
    midsum[p] = pairwise(routes) % MOD
    
print((sum(endsum) + sum(midsum)) % MOD)