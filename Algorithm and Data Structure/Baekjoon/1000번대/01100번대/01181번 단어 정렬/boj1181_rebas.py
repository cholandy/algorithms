from sys import stdin
input = stdin.readline
n = int(input())
a = set()
for _ in range(n):
    s = input().strip()
    a.add((len(s), s))
for i, j in sorted(a):
    print(j)