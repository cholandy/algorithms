import itertools as it
m, n = map(int,input().split())
for p in it.permutations(range(1,m+1), n): print(*p)