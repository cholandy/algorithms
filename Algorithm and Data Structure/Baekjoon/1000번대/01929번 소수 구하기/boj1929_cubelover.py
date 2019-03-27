a, b = map(int, input().split())
d = [1 for _ in range(b + 1)]
d[1] = 0
i = 2
while i * i <= b:
    if d[i]:
        j = i + i
        while j <= b:
            d[j] = 0
            j += i
    i += 1
for i in range(a, b + 1):
    if d[i]:
        print(i)