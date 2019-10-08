from collections import deque
n, k = map(int,input().split())

dist = [[-1]*500001 for i in range(2)] # odd even
Q = deque([(n,1)])
dist[1][n] = 0
while Q:
    pos, oe = Q.popleft()
    for np in pos-1, pos+1, 2*pos:
        if not (0<=np<=500000): continue
        if dist[1-oe][np] != -1: continue
        dist[1-oe][np] = dist[oe][pos]+1
        Q.append((np,1-oe))

ans = 999999
step = 1
while k <= 500000:
    t = dist[step%2][k]
    if t < step: ans = min(ans, step-1)
    k+= step
    step+= 1
print(ans if ans != 999999 else -1)