def mkct(word) :
    ct = [0 for x in range(26)]
    for c in word :
        ct[ord(c)-0x41] += 1
    return ct

def issim(ct1, ct2) :
    cmp = [x-y for x,y in zip(ct1, ct2)]
    if not all(-2<x<2 for x in cmp) :
        return False
    if cmp.count(1) > 1 :
        return False
    if cmp.count(-1) > 1 :
        return False
    return True

def solve(words) :
    ref, *words = words
    rct = mkct(ref)
    return sum(issim(rct, mkct(x)) for x in words)

n = int(input())
w = [input() for x in range(n)]
print(solve(w))
