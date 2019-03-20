def underprime(n):
    res = 0
    for p in plist:
        if p**2 > n: break
        while n%p==0:
            res+= 1
            n//= p
    if n > 1: res+= 1
    return sieve[res] != 0

a, b = map(int,input().split())
sieve = list(range(b+1))
sieve[1] = 0
for p in range(2, int((b+1)**0.5+1)):
    if not sieve[p]: continue
    for q in range(p*2, b+1, p): sieve[q] = 0
plist = list(filter(None, sieve))

res = 0
for i in range(a, b+1):
    res+= underprime(i)
print(res)