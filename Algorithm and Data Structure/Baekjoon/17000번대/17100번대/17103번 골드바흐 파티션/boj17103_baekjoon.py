from collections import deque
import sys
sys.stdin = open('input.txt.', 'r')

primes = deque()
chck = [False]*1000001
for i in range(2, 1000001):
    if chck[i] == False:
        primes.append(i)
        for j in range(2*i, 1000001, i):
            chck[j] = True


for tc in range(int(input())):
    n = int(input())
    ans = 0
    for p in primes:
        if n-p >= 2 and p <= n-p:
            if chck[n-p] == False:
                ans += 1
        else:
            break
    print(ans)
