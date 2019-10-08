from sys import stdin, stdout

MAX = 1000000
primes = [1 for _ in range(MAX+1)]
# primes[0] = primes[1] = 0

for i in range(2, MAX+1):
    if i*i > MAX:
        break
    if primes[i] is 1:
        for j in range(i*i, MAX+1, i):
            primes[j] = 0
n = int(input())
arr = []
while n:
    num = int(input())
    ans = 0
    for i in range(2, MAX+1):
        if num-i >= 2 and i <= num-i:
            if primes[num-i] == 1:
                ans += 1
        else:
            break
    arr.append(str(ans)+'\n')
    n -= 1

stdout.writelines(arr)
