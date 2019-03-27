n = int(input())
d = [0 for _ in range(n+1)]
d[1] = r = int(input())
for i in range(2, n + 1):
    t = int(input())
    d[i] = d[i - 2] + t
    if i == 2:
        d[i] += r
    if i > 2:
        d[i] = max(d[i], d[i - 3] + t + r)
    r = t
print(d[n])