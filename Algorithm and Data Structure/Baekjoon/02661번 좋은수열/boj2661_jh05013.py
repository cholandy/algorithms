def goodlen(seq, n):
    L = len(seq)
    for i in range(L-1, L-n-1, -1):
        if seq[i] != seq[i-n]: return True
    return False

def good(seq):
    for i in range(len(seq)//2):
        if not goodlen(seq, i+1): return False
    return True

def backtrack():
    if len(L) == n: return True
    for i in range(1, 4):
        L.append(i)
        if good(L) and backtrack(): return True
        L.pop()

L = []
n = int(input())
backtrack()
print(*L, sep='')