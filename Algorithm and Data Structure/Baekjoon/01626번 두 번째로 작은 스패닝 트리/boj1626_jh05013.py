import heapq
def Prim(adj):
    n = len(adj)-1; edges = []; mst = [[] for i in range(n+1)]
    grouped = [False]*(n+1); grouped[1] = True
    gn = 1; cost = 0
    for j, c in adj[1]: heapq.heappush(edges, (c,1,j))
    while edges and gn < n:
        c, i, j = heapq.heappop(edges)
        if grouped[j]: continue
        grouped[j] = True; gn+= 1; cost+= c; mst[i].append((j,c)); mst[j].append((i,c))
        for k, c in adj[j]: heapq.heappush(edges, (c,j,k))
    if gn != n: return float('inf'), []
    return cost, mst

from math import log2
from collections import deque
class LCA:
    def __init__(self, adj):
        n = len(adj); parent = [0]*n; depth = [0]*n; dist = [-1]*n
        Q = deque(); Q.append(1); depth[1] = 1
        while len(Q):
            p = Q.popleft()
            for son, cost in adj[p]:
                if depth[son]: continue
                depth[son] = depth[p] + 1; dist[son] = cost
                parent[son] = p; Q.append(son)
        # [a][b] is 2^a-th parent of b
        pk = [parent] + [[0]*n for i in range(int(log2(n)))]
        w1 = [dist] + [[-1]*n for i in range(int(log2(n)))]
        w2 = [[-1]*n] + [[-1]*n for i in range(int(log2(n)))]
        for d in range(1, len(pk)):
            for i in range(1, n):
                anc = pk[d-1][i]
                pk[d][i] = pk[d-1][anc]
                w1[d][i] = max(w1[d-1][i], w1[d-1][anc])
                w2cand = (w1[d-1][i], w2[d-1][i], w1[d-1][anc], w2[d-1][anc])
                w2cand = list(filter(lambda x: x<w1[d][i], w2cand))
                w2[d][i] = max(w2cand) if w2cand else -1
        self.n = n; self.pk = pk; self.w1 = w1; self.w2 = w2
        self.depth = depth; self.dist = dist

    def kth(self, a, k):
        j = 0; e1 = -1; e2 = -1
        while k:
            if k % 2 == 1:
                new1 = self.w1[j][a]; new2 = self.w2[j][a]
                e2, e1 = sorted({e1,e2,new1,new2,-1,-2})[-2:]
                a = self.pk[j][a]
            k//= 2; j+= 1
        return a, e1, e2
    
    def LCA(self, a, b):
        # LCA of a and b given buildLCA array and depth
        if self.depth[a] < self.depth[b]: a, b = b, a
        a, e1, e2 = self.kth(a, self.depth[a]-self.depth[b])
        if a == b: return a, e1, e2
        for j in range(len(self.pk)-1, -1, -1):
            if self.pk[j][a] != 0 and self.pk[j][a] != self.pk[j][b]:
                e3, e4, e5, e6 = self.w1[j][a], self.w2[j][a], self.w1[j][b], self.w2[j][b]
                e2, e1 = sorted({-2,-1,e1,e2,e3,e4,e5,e6})[-2:]
                a = self.pk[j][a]; b = self.pk[j][b]
        e3, e4, e5, e6 = self.w1[0][a], self.w2[0][a], self.w1[0][b], self.w2[0][b]
        e2, e1 = sorted({-2,-1,e1,e2,e3,e4,e5,e6})[-2:]
        return self.pk[0][a], e1, e2

from sys import stdin
input = stdin.readline
v, e = map(int,input().split())
adj = [[] for i in range(v+1)]
edges = []
for i in range(e):
    a, b, c = map(int,input().split())
    adj[a].append((b,c)); adj[b].append((a,c))
    edges.append((a,b,c))
cost, adj = Prim(adj)
if not adj: print(-1); exit()
tree = LCA(adj)
second = float('inf')
for a, b, c in edges:
    lca, e1, e2 = tree.LCA(a,b)
    if 0 <= e1 < c: second = min(second, cost+c-e1)
    elif 0 <= e2 < c: second = min(second, cost+c-e2)
print(second if second != float('inf') else -1)