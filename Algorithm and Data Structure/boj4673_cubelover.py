def f(x):
    return f(x // 10) + x % 10 if x else 0
d = [False for _ in range(11111)]
for i in range(10000):
    d[i + f(i)] = True
    if not d[i]:
        print(i)