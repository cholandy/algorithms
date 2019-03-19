class SegTree:
    def __init__(self, n, compose, identity):
        size = 1; self.identity = identity
        while size < n: size<<= 1
        self.arr = [identity]*(size*2); self.size = size; self.c = compose
    
    def construct(self, L):
        for i in range(len(L)): self.arr[self.size+i] = L[i]
        for i in range(self.size-1, -1, -1): self.arr[i] = self.c(self.arr[2*i], self.arr[2*i+1])
    
    def update(self, i, val):
        i+= self.size; self.arr[i] = val
        while i > 1: i//=2; self.arr[i] = self.c(self.arr[i*2], self.arr[i*2+1])
    
    def query(self, l, r):
        return self.internal(l, r, 1, 0, self.size-1)
    
    def internal(self, l, r, node, nl, nr):
        if r < nl or l > nr: return self.identity
        if l <= nl and nr <= r: return self.arr[node]
        mid = (nl+nr)//2
        return self.c(self.internal(l, r, node*2, nl, mid), self.internal(l, r, node*2+1, mid+1, nr))

def sign(n):
    n = int(n)
    if n == 0: return 0
    if n > 0: return 1
    return -1

from sys import stdin
input = stdin.readline
while 1:
    try: n, k = map(int,input().split())
    except: break
    x = list(map(sign,input().split()))
    ST = SegTree(n, lambda x,y:x*y, 1)
    ST.construct(x)
    for i in range(k):
        q, a, b = input().split()
        a, b = int(a), int(b)
        if q == "C": ST.update(a-1, sign(b))
        else: print("0+-"[ST.query(a-1, b-1)], end='')
    print()