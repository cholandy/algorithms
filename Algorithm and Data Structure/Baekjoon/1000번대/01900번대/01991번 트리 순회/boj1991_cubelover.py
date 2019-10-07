d = dict()
s = set()
for _ in range(int(input())):
    a, b, c = input().split()
    s.add(b)
    s.add(c)
    d[a] = (b, c)
def Pre(x):
    if x == '.':
        return
    print(x, end = '')
    Pre(d[x][0])
    Pre(d[x][1])
def In(x):
    if x == '.':
        return
    In(d[x][0])
    print(x, end = '')
    In(d[x][1])
def Post(x):
    if x == '.':
        return
    Post(d[x][0])
    Post(d[x][1])
    print(x, end = '')
x = (d.keys() - s).pop()
Pre(x)
print()
In(x)
print()
Post(x)
print()