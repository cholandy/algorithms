a = [list(map(int, input().split())) for _ in range(9)]
b = [[0 for _ in range(9)] for _ in range(9)]
c = [[0 for _ in range(9)] for _ in range(9)]
d = [[0 for _ in range(9)] for _ in range(9)]
for i in range(9):
    for j in range(9):
        if a[i][j]:
            b[i][a[i][j] - 1] = 1
            c[j][a[i][j] - 1] = 1
            d[i // 3 * 3 + j // 3][a[i][j] - 1] = 1
def f(x, y):
    if x == 9:
        return True
    if y == 9:
        return f(x + 1, 0)
    if a[x][y]:
        return f(x, y + 1)
    for i in range(9):
        if not b[x][i] and not c[y][i] and not d[x // 3 * 3 + y // 3][i]:
            b[x][i] = 1
            c[y][i] = 1
            d[x // 3 * 3 + y // 3][i] = 1
            if f(x, y + 1):
                a[x][y] = i + 1
                return True
            b[x][i] = 0
            c[y][i] = 0
            d[x // 3 * 3 + y // 3][i] = 0
    return False
f(0, 0)
print('\n'.join(map(lambda t: ' '.join(map(str, t)), a)))