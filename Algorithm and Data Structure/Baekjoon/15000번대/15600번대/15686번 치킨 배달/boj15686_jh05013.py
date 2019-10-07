from sys import stdin
input = stdin.readline
MIS = lambda: map(int,input().split())

from itertools import combinations
n, m = MIS()
chicken = []
house = []
for i in range(n):
    for j, x in enumerate(MIS()):
        if x == 1: house.append((i,j))
        if x == 2: chicken.append((i,j))
res = float('inf')
for C in combinations(chicken, m):
    dist = 0
    for hx, hy in house:
        dist+= min((abs(cx-hx)+abs(cy-hy)) for cx, cy in C)
    res = min(res, dist)
print(res)