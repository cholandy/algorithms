import sys
def nCr(n,r):
    print(fac(n)//(fac(n-r)*fac(r)))

def fac(x):
    if x == 1 or x == 0:return 1
    return x*fac(x-1)

N = int(input())
for _ in range(N):
    A, B = map(int,sys.stdin.readline().split())
    nCr(B,A)