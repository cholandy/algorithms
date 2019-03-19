import sys
input = sys.stdin.readline

n = int(input())
g = [[] for _ in range(n)]
for _ in range(n - 1):
    i, j = map(int, input().split())
    g[i - 1].append(j - 1)
    g[j - 1].append(i - 1)
p = [0] * n
q = [(0, 0)]
for x, y in q:
    p[x] = y + 1
    for z in g[x]:
        if z != y:
            q.append((z, x))
print('\n'.join(map(str, p[1:])))
