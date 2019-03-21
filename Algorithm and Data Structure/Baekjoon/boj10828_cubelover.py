s = list()
for _ in range(int(input())):
    a = input().split()
    if a[0] == 'push':
        s.append(int(a[1]))
    if a[0] == 'pop':
        if s:
            print(s[-1])
            s.pop()
        else:
            print(-1)
    if a[0] == 'size':
        print(len(s))
    if a[0] == 'empty':
        print(0 if s else 1)
    if a[0] == 'top':
        print(s[-1] if s else -1)