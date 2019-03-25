from itertools import combinations
n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
home, chicken = [], []
ans = 1e9
for i in range(n):
    for j in range(n):
        if a[i][j] == 1:
            home.append((i+1, j+1))
        elif a[i][j] == 2:
            chicken.append((i+1, j+1))
for k in combinations(chicken, m):
    s = 0
    for hx, hy in home:
        d = 1e9
        for cx, cy in k:
            d = min(d, abs(hx-cx)+abs(hy-cy))
        s += d
    ans = min(ans, s)
print(ans)


