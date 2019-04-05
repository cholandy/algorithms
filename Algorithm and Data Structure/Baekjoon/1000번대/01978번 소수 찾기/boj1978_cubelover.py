input()
# a = map(int, input().split())
a=list(range(10000))
r = 0
for i in a:
    if i == 1:
        continue
    fl = 1
    for j in range(2,i):
        if not i % j:
            fl = 0
    r += fl
print(r)