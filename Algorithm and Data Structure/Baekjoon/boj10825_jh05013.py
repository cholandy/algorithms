def value(s):
    return (-int(s[1]), int(s[2]), -int(s[3]), s[0])

a = []
for r in range(int(input())):
    a.append(input().split())
for s in sorted(a, key=value):
    print(s[0])