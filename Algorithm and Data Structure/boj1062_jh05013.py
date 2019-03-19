from itertools import combinations
from sys import exit

input = raw_input
range = xrange
n, k = map(int,input().split())
word = [input() for i in range(n)]
k-= 5
if k < 0: print(0); exit()
alpha = 'bdefghjklmopqrsuvwxyz'
res = 0

for C in combinations(alpha, k):
    use = [False]*26
    for i in 0, 2, 8, 13, 19: use[i] = True
    for c in C: use[ord(c)-ord('a')] = True
    cur = 0
    for w in word: cur+= all(use[ord(c)-ord('a')] for c in w)
    res = max(res, cur)
print(res)