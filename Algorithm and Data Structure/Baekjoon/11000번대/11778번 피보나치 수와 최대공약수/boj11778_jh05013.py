from fractions import gcd
A = ((1,1),(1,0))

def multi(a, b, k):
    return (((a[0][0]*b[0][0]+a[0][1]*b[1][0])%k,
             (a[0][0]*b[0][1]+a[0][1]*b[1][1])%k),
            ((a[1][0]*b[0][0]+a[1][1]*b[1][0])%k,
             (a[1][0]*b[0][1]+a[1][1]*b[1][1])%k))

def power(L, p, k):
    if p == 1:
        return L
    sq = power(L, p//2, k)
    if p%2==0:
        return multi(sq,sq,k)
    return multi(multi(sq,sq,k),L,k)

n, m = map(int,input().split())
print(power(A,gcd(n,m),1000000007)[0][1])