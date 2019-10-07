from itertools import combinations
for T in range(int(input())):
    n = int(input())
    x = []
    y = []
    best = float('inf')
    for i in range(n):
        a, b = map(int,input().split())
        x.append(a)
        y.append(b)
    allx = sum(x)
    ally = sum(y)
    for C in combinations(range(n), n//2):
        resx = allx
        resy = ally
        for i in C:
            resx-= 2*x[i]
            resy-= 2*y[i]
        best = min(best, resx**2+resy**2)
    if not best: print(1234567)
    else: print("%.6f"%(best**0.5))