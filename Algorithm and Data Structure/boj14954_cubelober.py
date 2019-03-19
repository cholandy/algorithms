n = input()
for _ in range(99): n = str(sum(x * x for x in map(int, n)))
print('HAPPY' if n == '1' else 'UNHAPPY')