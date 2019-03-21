from queue import Queue

n = int(input())
adj = [set() for i in range(n+1)]
while 1:
    a, b = map(int,input().split())
    if a == b == -1:
        break
    adj[a].add(b)
    adj[b].add(a)

def bacon(i):
    dist = [float('inf')]*(n+1)
    dist[0] = 0
    dist[i] = 0
    Q = Queue()
    Q.put(i)
    while not Q.empty():
        cur = Q.get()
        depth = dist[cur]
        for fr in adj[cur]:
            if dist[fr] == float('inf'):
                dist[fr] = depth+1
                Q.put(fr)
    return max(dist)

L = [9999]+list(map(bacon, range(1,n+1)))
score = min(L)
print(score, L.count(score))
for i in range(1,n+1):
    if L[i] == score:
        print(i, end=' ')