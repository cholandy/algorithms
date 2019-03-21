import sys
sys.setrecursionlimit(1000000)
input=sys.stdin.readline
while True:
    m, n = map(int, input().split())
    if not n:
        break
    a = [list(map(ord, input().split())) for _ in range(n)]
    def f(i, j):
        if i < 0 or i >= n or j < 0 or j >= m or a[i][j] != 49:
            return
        a[i][j] = 48
        for k in range(-1, 2):
            for l in range(-1, 2):
                f(i + k, j + l)
    r = 0
    for i, b in enumerate(a):
        for j, x in enumerate(b):
            if x == 49:
                r += 1
                f(i, j)
    print(r)
