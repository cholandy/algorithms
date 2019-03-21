import sys
input = sys.stdin.readline

n, m = map(int, input().split())
d = [0] * 128
if n:
    d[n] = 1
for i in range(m):
    d = [0] + [d[j] + d[j + 2] for j in range(126)] + [d[-2]]
print(sum(d))
