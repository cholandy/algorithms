n = int(input())
i = 1
while i * (i - 1) * 3 + 1 < n:
    i += 1
print(i)