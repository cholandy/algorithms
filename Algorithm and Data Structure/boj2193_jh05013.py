n = int(input())
a, b = 1, 1
for i in range(1, n):
    a, b = a+b, a
print(b)