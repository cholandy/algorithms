import sys
input = sys.stdin.readline
q = []
for _ in range(int(input())):
    x, *a = input().split()
    if x == 'push':
        q.append(a[0])
    elif x == 'pop':
        print(q.pop(0) if q else -1)
    elif x == 'size':
        print(len(q))
    elif x == 'empty':
        print(0 if q else 1)
    elif x == 'front':
        print(q[0] if q else -1)
    else:
        print(q[-1] if q else -1)