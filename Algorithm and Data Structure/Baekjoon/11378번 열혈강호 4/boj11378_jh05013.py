from collections import deque, defaultdict
def Dinic(G, C, s, t):
    def send(u, limit):
        if limit <= 0: return 0
        if u == t: return limit
        val = 0
        for v in G[u]:
            res = C[(u,v)]-flow[(u,v)]
            if level[v] == level[u]+1 and res>0:
                a = send(v, min(limit-val, res))
                flow[(u,v)]+= a; flow[(v,u)]-= a; val+= a
        if val == 0: level[u]-= 1
        return val
    Q, tot, n, flow = deque(), 0, len(G), defaultdict(int)
    while 1:
        Q.append(s); level = [-1]*n; level[s] = 0
        while len(Q) > 0:
            u = Q.popleft()
            for v in G[u]:
                if level[v] == -1 and C[(u,v)] > flow[(u,v)]: level[v] = level[u]+1; Q.append(v)
        if level[t] == -1: return tot#, flow
        tot+= send(s, sum(C[(s,v)] for v in G[s]))

def addedge(i, j, cap):
    G[i].append(j); G[j].append(i); C[(i,j)]+= cap

# 0: source
# 1: bonus
# 2 ~ 1+n: employee
# 2+n ~ 1+n+m: work
# 2+n+m: sink

n, m, k = map(int,input().split())
G = [[] for i in range(3+n+m)]
C = defaultdict(int)
addedge(0, 1, k)
for i in range(n):
    addedge(0, 2+i, 1)
    addedge(1, 2+i, k)
    JCOUNT, *job = map(int,input().split())
    for j in job: addedge(2+i, 1+n+j, 1)
for j in range(m): addedge(2+n+j, 2+n+m, 1)
print(Dinic(G, C, 0, 2+n+m))