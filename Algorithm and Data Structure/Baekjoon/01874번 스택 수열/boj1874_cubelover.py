import sys
input = sys.stdin.readline

n = int(input())
a = list(int(input()) for _ in range(n))
s = list()
r = ''
j = 0
for i in range(1, n + 1):
    r += '+\n'
    s.append(i)
    while j < n and s and s[-1] == a[j]:
        r += '-\n'
        s.pop()
        j += 1
print(r if j == n else 'NO')