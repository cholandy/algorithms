import sys
from heapq import *

input = sys.stdin.readline

n = int(input())
a = []
p = [0]
q = dict()

for i in range(n):
    x, y, z = map(int, input().split())
    a.append((x, -1, -y))
    a.append((z, 1, y))

a.sort()

for x, y, z in a:
    t = p[0]
    if y == 1:
        if -z in q:
            q[-z] += 1
        else:
            q[-z] = 1
        while p[0] in q and q[p[0]]:
            q[p[0]] -= 1
            heappop(p)
    else:
        heappush(p, z)
    if p[0] != t:
        print(x, -p[0], end = ' ')
