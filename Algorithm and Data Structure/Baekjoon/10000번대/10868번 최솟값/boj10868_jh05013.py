class SegTree:
    def __init__(self, n, compose, identity):
        self.n, self.c, self.id = 1, compose, identity
        while self.n < n: self.n<<= 1
        self.arr = [self.id]*(self.n*2)
    
    def construct(self, L):
        for i in range(len(L)): self.arr[self.n+i] = L[i]
        for i in range(self.n-1, -1, -1): self.arr[i] = self.c(self.arr[2*i], self.arr[2*i+1])
    
    def update(self, i, val):
        i+= self.n; self.arr[i] = val
        while i > 1: i//=2; self.arr[i] = self.c(self.arr[i*2], self.arr[i*2+1])
    
    def query(self, l, r):
        al, ar = self.id, self.id
        l+= self.n; r+= self.n+1
        while l < r:
            if l&1: al = self.c(al, self.arr[l]); l+= 1
            if r&1: r-= 1; ar = self.c(ar, self.arr[r])
            l>>=1; r>>=1
        return self.c(al, ar)

input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())
INF = float('inf')

n, m = MIS()
ST = SegTree(n, min, INF)
ST.construct([int(input()) for i in range(n)])
for i in range(m):
    a, b = MIS()
    print(ST.query(a-1, b-1))