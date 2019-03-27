a = int(input())
b = int(input())
def ispr(x):
    if x == 1:
        return False
    j = 2
    while j * j <= x:
        if not x % j:
            return False
        j += 1
    return True
s = 0
for i in range(a, b + 1):
    if ispr(i):
        s += i
if s == 0:
    s = -1
print(s)
for i in range(a, b + 1):
    if ispr(i):
        print(i)
        break