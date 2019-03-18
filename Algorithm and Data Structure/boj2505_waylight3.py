import sys

def good(a):
    for i in range(len(a)):
        if a[i] != i + 1:
            return False
    return True

n = int(input())
a = list(map(int, input().split()))
if good(a):
    print(1, 1)
    print(2, 2)
    sys.exit()
for i in range(n):
    if a[i] != i + 1:
        s = i
        break
for i in range(n):
    if a[n - i - 1] != n - i:
        e = n - i - 1
        break
for i in range(n):
    if a[i] == s + 1:
        first = i
        break
b = a[:s] + a[s:first + 1][::-1] + a[first + 1:e] + a[e:]
if good(b):
    print(s + 1, first + 1)
    print(1, 1)
    sys.exit()
for i in range(n):
    if b[i] != i + 1:
        ss = i
        break
for i in range(n):
    if b[n - i - 1] != n - i:
        ee = n - i - 1
        break
c = b[:ss] + b[ss:ee + 1][::-1] + b[ee + 1:]
if good(c):
    print(s + 1, first + 1)
    print(ss + 1, ee + 1)
else:
    for i in range(n):
        if a[i] == e + 1:
            last = i
            break
    b = a[:s] + a[s:last] + a[last:e + 1][::-1] + a[e + 1:]
    if good(b):
        print(last + 1, e + 1)
        print(1, 1)
        sys.exit()
    for i in range(n):
        if b[i] != i + 1:
            ss = i
            break
    for i in range(n):
        if b[n - i - 1] != n - i:
            ee = n - i - 1
            break
    c = b[:ss] + b[ss:ee + 1][::-1] + b[ee + 1:]
    if good(c):
        print(last + 1, e + 1)
        print(ss + 1, ee + 1)
    else:
        while True:
            pass