LIM = 10000000
sieve = list(range(LIM)); sieve[1] = 0
for i in range(2, int(LIM**.5)+1):
    if not sieve[i]: continue
    for j in range(i*i, LIM, i): sieve[j] = 0
sieve = list(filter(None, sieve))

print(sieve[int(input())-1])