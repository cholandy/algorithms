from sys import stdin
input = stdin.readline

from collections import deque
def BFS(i):
    visit = [False]*(n+1)
    visit[i] = True
    Q = deque()
    Q.append(i)
    while len(Q):
        p = Q.popleft()
        for q in adj[p]:
            if visit[q]: continue
            visit[q] = True
            Q.append(q)
    return visit

n, k = map(int,input().split())
adj = [[] for i in range(n+1)]
for i in range(k):
    a, b = map(int,input().split())
    adj[a].append(b)
arr = [BFS(i) for i in range(n+1)]

s = int(input())
for i in range(s):
    a, b = map(int,input().split())
    if arr[a][b]: print(-1)
    elif arr[b][a]: print(1)
    else: print(0)