MAX = 10000
prime = [True]*(MAX + 1)
prime[0] = False
prime[1] = False

for i in range(2, MAX + 1):
    if not prime[i]:
        continue
    for j in range(i*2, MAX + 1, i):
        prime[j] = False

T = int(input())
for i in range(T):
    n = int(input())
    for j in range(int(n/2), 1, -1):
        if prime[j] and prime[n - j]:
            print('{0} {1}'.format(j, n - j))
            break
