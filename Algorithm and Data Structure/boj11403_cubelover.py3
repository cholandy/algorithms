n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
for k in range(n):
    for i in range(n):
        for j in range(n):
            if a[i][k] and a[k][j]:
                a[i][j] = 1
print('\n'.join(map(lambda t: ' '.join(map(str, t)), a)))