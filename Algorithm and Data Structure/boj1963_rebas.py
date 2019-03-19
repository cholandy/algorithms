def change(n, i, j):
    s = str(n)
    s = s[:i] + str(j) + s[i+1:]
    return int(s)

A = [True]*10000
for i in range(2, 101):
    if A[i]:
        for j in range(i*i, 10000, i):
            A[j] = False

for _ in range(int(input())):
    x, y = map(int, input().split())

    if x == y:
        print(0)
        continue

    c = [False]*10000
    d = [0]*10000
    q = [x]
    c[x] = True

    while q:
        now = q.pop(0)
        for i in range(4):
            for j in range(10):
                if i == 0 and j == 0: continue
                t = change(now, i, j)
                if c[t] is False and A[t]:
                    q.append(t)
                    c[t] = True
                    d[t] = d[now] + 1

    print(d[y] if d[y] is not 0 else "Impossible")