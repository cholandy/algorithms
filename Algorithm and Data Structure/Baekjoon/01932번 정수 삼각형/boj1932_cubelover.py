n = int(input())
a = [list() for i in range(n)]
for i in range(n):
    a[i] = list(map(int, input().split()))
    if not i:
        continue
    a[i][0] += a[i - 1][0]
    for j in range(1,i):
        a[i][j] += max(a[i - 1][j], a[i - 1][j - 1])
    a[i][i] += a[i - 1][i - 1]
print(max(a[n - 1]))