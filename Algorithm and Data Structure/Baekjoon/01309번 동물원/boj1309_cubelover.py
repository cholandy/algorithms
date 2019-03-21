a = b = c = 1
for _ in range(int(input())):
    a, b, c = map(lambda t: t % 9901, (b + c, a + b + c, a + b))
print(b)