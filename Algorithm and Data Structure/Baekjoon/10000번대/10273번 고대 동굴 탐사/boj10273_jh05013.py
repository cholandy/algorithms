from sys import setrecursionlimit as SRL, stdin
SRL(150000)
input = stdin.readline

from collections import deque
def Toposort(n, adj):
    indegree = [0]*(n+1); indegree[0] = -1; L = []
    for i in range(1,n+1):
        for j in adj[i]: indegree[j]+= 1
    Q = deque()
    for i in range(1,n+1):
        if indegree[i] == 0: Q.append(i)
    for i in range(n):
        if len(Q) == 0: raise Exception
        p = Q.popleft(); L.append(p)
        for j in adj[p]:
            indegree[j]-= 1
            if indegree[j] == 0: Q.append(j)
    return L

for TEST in range(int(input())):
    n, e = map(int,input().split())
    value = [0]+list(map(int,input().split()))
    adj = [{} for i in range(n+1)]
    for i in range(e):
        a, b, c = map(int,input().split())
        if b in adj[a]: adj[a][b] = min(adj[a][b], c)
        else: adj[a][b] = c
    order = Toposort(n, adj)
    opt = [-float('inf')]*(n+1)
    opt[1] = value[1]
    prev = [None]*(n+1)
    
    for p in order:
        for q in adj[p]:
            res = opt[p]-adj[p][q]+value[q]
            if res > opt[q]:
                opt[q] = res
                prev[q] = p
    maxres = max(opt)
    optorder = [opt.index(maxres)]
    while optorder[-1]:
        optorder.append(prev[optorder[-1]])
    optorder.pop()
    print(maxres, len(optorder))
    print(*reversed(optorder))