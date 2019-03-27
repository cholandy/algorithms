from sys import stdin
input = stdin.readline
from math import log2

def buildLCA(parent1):
    # [a][b] is 2^a=th parent of b
    n = len(parent1)
    parentk = [parent1] + [[0]*n for i in range(int(log2(n)))]
    for d in range(1, len(parentk)):
        for i in range(1, n):
            parentk[d][i] = parentk[d-1][parentk[d-1][i]]
    return parentk

def LCA(pk, depth, a, b):
    # LCA of a and b given buildLCA array and depth
    if depth[a] < depth[b]:
        a, b = b, a
    diff = depth[a] - depth[b]
    j = 0
    while diff:
        if diff % 2 == 1:
            a = pk[j][a]
        diff//= 2
        j+= 1
    if a != b:
        for j in range(len(pk)-1, -1, -1):
            if pk[j][a] != 0 and pk[j][a] != pk[j][b]:
                a = pk[j][a]
                b = pk[j][b]
        a = pk[0][a]
    return a

from queue import Queue
n = int(input())
adj = [[] for i in range(n+1)]
for i in range(n-1):
    a, b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)
parent = [0]*(n+1)
depth = [0]*(n+1)
Q = Queue()
Q.put(1)
depth[1] = 1
while not Q.empty():
    p = Q.get()
    for son in adj[p]:
        if depth[son]:
            continue
        depth[son] = depth[p] + 1
        parent[son] = p
        Q.put(son)

pk = buildLCA(parent)        
for i in range(int(input())):
    a, b = map(int,input().split())
    print(LCA(pk, depth, a, b))