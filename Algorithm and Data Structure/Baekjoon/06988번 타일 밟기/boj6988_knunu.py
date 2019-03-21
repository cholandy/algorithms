N = int(input())
L = [int(x) for x in input().split()]
D = {int(x):True for x in L}
R = 0
for i in range(len(L)-1, 1, -1):
    if (L[i] * (L[i] + 1) / 2) - ((L[i] - i - 1) * (L[i] - i) / 2) <= R: break
    for j in range(1, i):
        d = L[i] - L[i-j]
        t = L[i]
        s, c = 0, 0

        while t > 0:
            if t in D:
                s += t
                c += 1
                t -= d
            else:
                break

        if c > 2:
            R = max(R, s)
            if c == i + 1:
                break

print(R)
