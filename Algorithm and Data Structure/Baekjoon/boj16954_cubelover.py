input = __import__('sys').stdin.readline
a = [input() for _ in range(8)]
d = [[False] * 8 for _ in range(8)]
d[7][0] = True
for i in range(8):
    for j in range(8 - i):
        for k in range(8):
            if a[j][k] == '#':
                d[i + j][k] = False
    td = [[False] * 8 for _ in range(8)]
    for j in range(8):
        for k in range(8):
            for x in range(-1, 2):
                for y in range(-1, 2):
                    if 0 <= j + x < 8 and 0 <= k + y < 8 and d[j + x][k + y]:
                        td[j][k] = True
    for j in range(8 - i):
        for k in range(8):
            if a[j][k] == '#':
                td[i + j][k] = False
    d = td
print(1 if sum(map(sum, d)) else 0)