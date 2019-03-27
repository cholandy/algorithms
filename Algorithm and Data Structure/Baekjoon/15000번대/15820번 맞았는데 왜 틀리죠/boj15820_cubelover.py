n, m = map(int, input().split())
for _ in range(n):
    a, b = input().split()
    if a != b:
        print('Wrong Answer')
        exit()
for _ in range(m):
    a, b = input().split()
    if a != b:
        print('Why Wrong!!!')
        exit()
print('Accepted')