from sys import stdin, stdout
from collections import deque

MAX = 1000001
primes = []
chk = [1]*MAX
for i in range(2, MAX):
    if chk[i] is 1:
        primes.append(i)
        for j in range(i*i, MAX, i):
            chk[j] = 0

answers = [0]*MAX
answers[4] = 1
for i in range(1, 41538):
    for j in range(i, len(primes)-i):
        answers[primes[i]+primes[j]] += 1

for t in range(int(input())):
    ans = answers[int(stdin.readline())]
    stdout.write(str(ans)+'\n')
