import sys
input = sys.stdin.readline
r = [[0] * 505 for _ in range(505)]
for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    r[a][b] += 1
    r[a][d] -= 1
    r[c][b] -= 1
    r[c][d] += 1
t = 0
for i in range(500):
    for j in range(500):
        if r[i][j]:
            t += 1
            r[i][j + 1] += r[i][j]
            r[i + 1][j] += r[i][j]
            r[i + 1][j + 1] -= r[i][j]
print(t)