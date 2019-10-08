import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = [0] + list(map(int, input().split()))
    d = [[0]*n, [s[i+1]+s[i+2] for i in range(n-1)]]
    v = list(range(n-1))
    for i in range(n):
        s[i + 1] += s[i]
    for k in range(2, n):
        td = []
        tv = []
        for j, x, y in (
            (
                j,
                *min(
                    (d[l-j][j] + d[j+k-l-1][l+1], l)
                    for l in range(v[j], v[j + 1] + 1)
                )
            )
            for j in range(n - k)
        ):
            td.append(x + s[j + k + 1] - s[j])
            tv.append(y)
        d.append(td)
        v = tv
    print(d[-1][0])
