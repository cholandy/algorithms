n, m = map(int, input().split())
x, y, d = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
a[x][y] = 2
dx, dy = (-1, 0, 1, 0), (0, 1, 0, -1)

def solve(x, y, d, ans):
    while True:
        c = False
        for k in range(4):
            nd = (d+3)%4
            nx, ny = x+dx[nd], y+dy[nd]
            d = nd
            if not a[nx][ny]:
                a[nx][ny] = 2
                ans += 1
                x, y = nx, ny
                c = True
                break
        if not c:
            if a[x-dx[d]][y-dy[d]] == 1:
                return ans
            else:
                x, y = x-dx[d], y-dy[d]

print(solve(x, y, d, 1))


