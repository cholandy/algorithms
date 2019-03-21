from math import log2
from collections import deque
class LCA:
    def __init__(_, adj):
        n = len(adj); depth = [0]*n
        Q = deque([1]); depth[1] = 1
        pk = [[0]*n for i in range(int(log2(n))+1)]
        pc1 = [[0]*n for i in range(int(log2(n))+1)]
        pc2 = [[0]*n for i in range(int(log2(n))+1)]
        while Q:
            p = Q.popleft()
            for son, c in adj[p]:
                if depth[son]: continue
                depth[son] = depth[p] + 1; pk[0][son] = p; Q.append(son)
                pc1[0][son] = pc2[0][son] = c
        for d in range(1, len(pk)):
            for i in range(1, n):
                pk[d][i] = pk[d-1][pk[d-1][i]]
                pc1[d][i] = min(pc1[d-1][i], pc1[d-1][pk[d-1][i]])
                pc2[d][i] = max(pc2[d-1][i], pc2[d-1][pk[d-1][i]])
        _.pk = pk; _.depth = depth
        _.pc1 = pc1; _.pc2 = pc2

    def LCA(_, a, b):
        if _.depth[a] < _.depth[b]: a, b = b, a
        k = _.depth[a] - _.depth[b]
        c1 = 10**12; c2 = -10**12
        j = 0
        while k:
            if k%2 == 1:
                c1 = min(c1, _.pc1[j][a])
                c2 = max(c2, _.pc2[j][a])
                a = _.pk[j][a]
            k//= 2; j+= 1
            
        if a == b: return (c1, c2)
        for j in range(len(_.pk)-1, -1, -1):
            if _.pk[j][a] != 0 and _.pk[j][a] != _.pk[j][b]:
                c1 = min(c1, _.pc1[j][a], _.pc1[j][b])
                c2 = max(c2, _.pc2[j][a], _.pc2[j][b])
                a = _.pk[j][a]; b = _.pk[j][b]
        c1 = min(c1, _.pc1[0][a], _.pc1[0][b])
        c2 = max(c2, _.pc2[0][a], _.pc2[0][b])
        return (c1, c2)

input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())

n = int(input())
adj = [[] for i in range(n+1)]
for i in range(n-1):
    a, b, c = MIS()
    adj[a].append((b,c))
    adj[b].append((a,c))
lca = LCA(adj)
for i in range(int(input())):
    a, b = MIS()
    print(*lca.LCA(a, b))