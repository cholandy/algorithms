from sys import stdin
input = stdin.readline

pos = []
one = []
neg = []
for i in range(int(input())):
    n = int(input())
    if n > 1: pos.append(n)
    elif n == 1: one.append(n)
    else: neg.append(n)
pos.sort(reverse=True)
neg.sort()

res = 0
for L in pos, neg:
    for i in range(0, len(L)-1, 2): res+= L[i]*L[i+1]
    if len(L)%2 == 1: res+= L[-1]
res+= len(one)
print(res)