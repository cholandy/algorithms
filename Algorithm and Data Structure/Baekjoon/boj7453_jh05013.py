from sys import stdin
input = stdin.readline
from collections import Counter
n = int(input())
A = []
B = []
C = []
D = []
for i in range(n):
    a, b, c, d = map(int,input().split())
    for x, L in (a,A), (b,B), (c,C), (d,D): L.append(x)

res = 0
CD = Counter()
for c in C:
    for d in D: CD[c+d]+= 1
for a in A:
    for b in B: res+= CD[-a-b]
print(res)