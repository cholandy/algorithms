input()
s = 0
r = -1000
for x in map(int, input().split()):
    s += x
    r = max(r, s)
    s = max(s, 0)
print(r)