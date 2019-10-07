n = int(input())
if n < 8:
    print(-1)
else:
    sieve = list(range(n))
    sieve[1] = 0
    for i in range(2,1001):
        for j in range(2*i, n, i):
            sieve[j] = 0
    prime = list(filter(lambda x:x, sieve))    
    if n%2 == 0:
        a, b = 2, 2
        n-= 4
    else:
        a, b = 2, 3
        n-= 5
    for p in prime:
        if sieve[n-p]:
            print(a, b, p, n-p)
            break