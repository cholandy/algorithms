import sys, array
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    d = a = list(map(int, input().split()))
    for k in range(1, n):
        d = [max(a[i] - d[i + 1], a[i + k] - d[i]) for i in range(n - k)]
    print(d[0] + sum(a) >> 1)
