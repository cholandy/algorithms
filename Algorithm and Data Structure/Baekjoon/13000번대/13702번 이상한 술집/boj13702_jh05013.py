def paramax(F, l, r, fail):
    # largest x, l~r, such that F(x) is true
    if l >= r: return l if F(l) else fail
    if l+1 == r:
        if F(l): return r if F(r) else l
        return fail
    mid = (l+r)//2
    if F(mid): return paramax(F, mid, r, fail)
    return paramax(F, l, mid-1, fail)

def F(v):
    res = 0
    for i in mak:
        res+= i//v
    return res >= k

from sys import stdin
inplist = list(map(int, stdin.read().split()))
n, k = inplist[:2]
mak = inplist[2:]
print(paramax(F, 1, 2**31, 0))
