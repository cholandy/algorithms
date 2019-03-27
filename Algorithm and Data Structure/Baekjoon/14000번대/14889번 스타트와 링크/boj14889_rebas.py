import sys
n = int(sys.stdin.readline())
a = [list(map(int, input().split())) for _ in range(n)]
c = [False]*n
ans = 1e9

def solve(cnt, idx):
    global ans
    if idx == n:
        return
    if cnt == n//2:
        s1, s2 = 0, 0
        for i in range(n):
            for j in range(n):
                if c[i] and c[j]:
                    s1 += a[i][j]
                if not c[i] and not c[j]:
                    s2 += a[i][j]
        ans = min(ans, abs(s1-s2))
        return
    c[idx] = True
    solve(cnt+1, idx+1)
    c[idx] = False
    solve(cnt, idx+1)

solve(0, 0)
print(ans)


