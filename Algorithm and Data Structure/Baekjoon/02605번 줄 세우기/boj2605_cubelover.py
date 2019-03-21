n = int(input())
a = list(map(int, input().split()))
d = list()
for i in range(n):
    d.insert(i - a[i], i + 1)
print(' '.join(map(str, d)))