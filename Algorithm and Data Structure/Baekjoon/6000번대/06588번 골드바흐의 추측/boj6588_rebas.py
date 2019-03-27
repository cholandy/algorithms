MAX = 1000000
prime = [False for _ in range(MAX+1)]

for i in range(2, MAX+1):
    if i*i > MAX:
        break
    if prime[i] is False:
        for j in range(i*i, MAX+1, i):
            prime[j] = True

while True:
    n = int(input())
    if n is 0:
        break
    for i in range(2, MAX+1):
        if prime[i] is False:
            j = n - i
            if prime[j] is False:
                print(n, "=", i, "+", j)
                break
