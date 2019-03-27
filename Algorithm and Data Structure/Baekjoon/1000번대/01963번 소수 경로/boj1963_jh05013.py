sieve = list(range(10000))
sieve[1] = 0
for i in range(2, 101):
    if not sieve[i]: continue
    for j in range(2*i, 10000, i): sieve[j] = 0

def change(p):
    s = str(p)
    L = list(s)
    for di in range(4):
        for d in range(10):
            if di == 0 and d == 0: continue
            L[di] = str(d)
            n = int(''.join(L))
            if sieve[n]: yield n
        L[di] = s[di]

from collections import deque
for TEST in range(int(input())):
    a, b = map(int,input().split())
    visit = [-1]*10000
    visit[a] = 0
    Q = deque()
    Q.append(a)
    while len(Q):
        i = Q.popleft()
        if i == b: break
        for j in change(i):
            if visit[j] != -1: continue
            visit[j] = visit[i]+1
            Q.append(j)
    if visit[b] != -1: print(visit[b])
    else: print("Impossible")