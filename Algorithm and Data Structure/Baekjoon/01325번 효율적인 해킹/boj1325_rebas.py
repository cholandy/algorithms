from collections import deque
from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
a = [[] for _ in range(n+1)]
check = [False for _ in range(n+1)]
ans = []
hacking = 0

def bfs(i):
    global hacking
    q = deque()
    q.append(i)
    check[i] = True
    cnt = 0
    while q:
        x = q.popleft()
        for k in a[x]:
            if check[k] is False:
                q.append(k)
                check[k] = True
                cnt += 1
    if hacking < cnt:
        hacking = cnt
        ans.clear()
        ans.append(i)
    elif hacking == cnt:
        ans.append(i)

for _ in range(m):
    u, v = map(int, input().split())
    a[v].append(u)
for i in range(1, n+1):
    check = [False for _ in range(n+1)]
    bfs(i)
ans.sort()
for i in ans:
    print(i, end=' ')
print()