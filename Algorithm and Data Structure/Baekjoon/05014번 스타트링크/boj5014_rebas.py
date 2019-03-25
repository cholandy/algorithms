from collections import deque

def bfs():
    q = deque()
    q.append(S)
    dist[S] = 0
    while q:
        x = q.popleft()
        if x == G:
            print(dist[x])
            return
        for nx in (x+U), (x-D):
            if 1 <= nx <= F and dist[nx] == -1:
                q.append(nx)
                dist[nx] = dist[x]+1
    print("use the stairs")

F, S, G, U, D = map(int, input().split())
dist = [-1]*(F+1)
bfs()


