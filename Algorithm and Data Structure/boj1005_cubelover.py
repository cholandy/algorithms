import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)
for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    c = [0 for _ in range(n)]
    d = [0 for _ in range(n)]
    g = [list() for _ in range(n)]
    for i in range(m):
        j, k = map(int, input().split())
        g[j - 1].append(k - 1)
        c[k - 1] += 1
    def f(x):
        c[x] = -1
        d[x] += a[x]
        for i in g[x]:
            c[i] -= 1
            d[i] = max(d[i], d[x])
            if not c[i]:
                f(i)
    for i in range(n):
        if not c[i]:
            f(i)
    print(d[int(input())-1])