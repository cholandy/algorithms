a = sorted([int(input()) for _ in range(9)])
s = sum(a)
for i in range(9):
    for j in range(i):
        if a[i] + a[j] + 100 == s:
            for k in range(9):
                if i != k and j != k:
                    print(a[k])