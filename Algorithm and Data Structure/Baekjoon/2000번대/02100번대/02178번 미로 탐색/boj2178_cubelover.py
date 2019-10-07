n, m = map(int, input().split())
a = [input() for _ in range(n)]
v = [[0 for _ in range(m)] for _ in range(n)]
def f(x, y, z):
    if x >= 0 and x < n and y >= 0 and y < m and a[x][y] == '1' and not v[x][y]:
        v[x][y] = z
        q.append((x, y))
q = list()
f(0, 0, 1)
while q:
    x, y = q.pop(0)
    for px, py in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        f(x + px, y + py, v[x][y] + 1)
print(v[n - 1][m - 1])