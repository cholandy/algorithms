direct = [
    (2, 1, 5, 0, 4, 3),
    (3, 1, 0, 5, 4, 2),
    (4, 0, 2, 3, 5, 1),
    (1, 5, 2, 3, 0, 4)
]
dx, dy = (0, 0, -1, 1), (1, -1, 0, 0)
n, m, x, y, k = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
c = list(map(int, input().split()))
dice, temp = [0]*6, [0]*6

for i in range(k):
    d = c[i]-1
    x, y = x+dx[d], y+dy[d]
    if x < 0 or x >= n or y < 0 or y >= m:
        x, y = x-dx[d], y-dy[d]
        continue
    for j in range(6):
        temp[j] = dice[j]
    for j in range(6):
        dice[j] = temp[direct[d][j]]
    if a[x][y]:
        dice[5] = a[x][y]
        a[x][y] = 0
    else:
        a[x][y] = dice[5]
    print(dice[0])

