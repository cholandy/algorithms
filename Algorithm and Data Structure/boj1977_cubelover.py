a = int(input())
b = int(input())
assert 0 < a <= b
m = 11111
s = 0
for i in range(111):
    if a <= i * i <= b:
        s += i * i
        m = min(m, i * i)
if s:
    print(s)
    print(m)
else:
    print(-1)