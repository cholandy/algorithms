squares = [i*i for i in range(1,101)]
m = int(input())
n = int(input())
s = 0
minv = 10001

for i in squares:
    if m<=i<=n:
        s+= i
        if minv > i:
            minv = i
if minv == 10001:
    print(-1)
else:
    print(s)
    print(minv)