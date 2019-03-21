n = int(input())
a = list(map(int, input().split()))
p = a[0] + a[1]
q = 2
r = 0
for i in range(2, n):
    if (a[i] + a[i - 1] + a[i - 2]) * q < p * 3:
        p, q, r = a[i] + a[i - 1] + a[i - 2], 3, i - 2
    if (a[i] + a[i - 1]) * q < p * 2:
        p, q, r = a[i] + a[i - 1], 2, i - 1
print(r)