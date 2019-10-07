from itertools import permutations as pm
m, n = map(int,input().split())
for p in pm(range(1,m+1), n): print(*p)