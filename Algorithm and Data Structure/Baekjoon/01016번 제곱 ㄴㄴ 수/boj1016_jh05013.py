a, b = map(int,input().split())
sieve = list(range(1000001))
sieve[0] = 0
sieve[1] = 0
target = list(range(a,b+1)) # target[i] is a+i
for i in range(2, 1000001):
    if sieve[i] == 0: continue
    for j in range(2*i, 1000001, i): sieve[j] = 0
    sq = i**2
    if sq > b: continue
    j = sq-(a%sq) if a%sq!=0 else 0
    for k in range(j, b-a+1, sq): target[k] = 0
print(sum(1 for i in target if i != 0))