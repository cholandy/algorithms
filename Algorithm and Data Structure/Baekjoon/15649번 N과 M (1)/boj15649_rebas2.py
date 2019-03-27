from sys import stdin
from itertools import permutations
input = stdin.readline

n, m = map(int, input().split())
for k in permutations([i for i in range(1, n+1)], m):
    print(" ".join(map(str, k)))

