def check(P):
    for i in range(len(P)-1):
        if ineq[i] == "<" and P[i] > P[i+1]: return False
        if ineq[i] == ">" and P[i] < P[i+1]: return False
    return True

from itertools import permutations
n = int(input())
ineq = input().split()
mint = (123,)
maxt = (-1,)
for P in permutations(range(10), n+1):
    if not check(P): continue
    mint = min(mint, P)
    maxt = max(maxt, P)
print(*maxt, sep='')
print(*mint, sep='')