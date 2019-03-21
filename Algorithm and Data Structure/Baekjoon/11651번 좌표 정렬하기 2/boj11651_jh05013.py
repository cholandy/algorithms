def value(s):
    a,b = map(int,s.split())
    return (b,a)

a = []
for r in range(int(input())):
    a.append(input())
for s in sorted(a, key=value):
    print(s)