from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
b = [
    [(0,1), (1,0), (1,1)],
    [(0,1), (0,2), (0,3)],
    [(1,0), (2,0), (3,0)],
    [(0,1), (0,2), (1,0)],
    [(0,1), (0,2), (-1,2)],
    [(1,0), (1,1), (1,2)],
    [(0,1), (0,2), (1,2)],
    [(1,0), (2,0), (2,1)],
    [(0,1), (1,1), (2,1)],
    [(0,1), (1,0), (2,0)],
    [(1,0), (2,0), (2,-1)],
    [(1,0), (1,1), (2,1)],
    [(0,1), (1,0), (-1,1)],
    [(0,1), (1,0), (1,-1)],
    [(0,1), (1,1), (1,2)],
    [(0,1), (0,2), (1,1)],
    [(1,0), (1,1), (1,-1)],
    [(1,0), (2,0), (1,-1)],
    [(1,0), (1,1), (2,0)]
]

def tetromino(x, y):
    global ans
    for i in range(19):
        s = a[x][y]
        for j in range(3):
            try:
                nx = x+b[i][j][0]
                ny = y+b[i][j][1]
                s += a[nx][ny]
            except IndexError:
                continue
        ans = max(ans, s)

def solve():
    for i in range (n):
        for j in range(m):
            tetromino(i, j)

ans = 0
solve()
print(ans)


