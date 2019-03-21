sieve = list(range(10000))
sieve[1] = 0
for i in range(2,101):
    for j in range(2*i, 10000, i):
        sieve[j] = 0
prime = list(filter(lambda x:x, sieve))

for T in range(int(input())):
    n = int(input())
    res = 0
    for p in prime:
        q = n-p
        if p>q:
            break
        if sieve[q]:
            res = p
    print(res, n-res)