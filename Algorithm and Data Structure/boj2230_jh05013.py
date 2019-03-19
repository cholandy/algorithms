from sys import stdin
input = stdin.readline
from bisect import bisect_left as bs

n, m = map(int,input().split())
seq = [int(input()) for i in range(n)]+[float('inf')]
seq.sort()
M = float('inf')
for idx in range(n):
    i = seq[idx]
    j = seq[bs(seq, i+m)]
    M = min(M, j-i)
print(M)