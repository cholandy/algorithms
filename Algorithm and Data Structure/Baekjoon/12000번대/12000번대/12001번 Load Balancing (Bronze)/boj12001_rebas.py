from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
x, y = [[] for _ in range(n)], [[] for _ in range(n)]
for i in range(n):
    x[i], y[i] = map(int, input().split())

def solve():
    ans = 1e9
    for i in range(n):
        for j in range(n):
            a, b, c, d = [0]*4
            for k in range(n):
                if x[k] < x[i]+1 and y[k] < y[j]+1:
                    a += 1
                if x[k] < x[i]+1 and y[k] > y[j]+1:
                    b += 1
                if x[k] > x[i]+1 and y[k] > y[j]+1:
                    c += 1
                if x[k] > x[i]+1 and y[k] < y[j]+1:
                    d += 1
            gap = max(a, b, c, d)
            ans = min(ans, gap)
    print(ans)

solve()


