from collections import deque
from math import factorial
def kthperm(k, n=9):
    fbase = []
    k-= 1
    for i in range(n):
        f = factorial(n-i-1)
        div = k//f
        k-= f*div
        fbase.append(div)
    number = list(range(n))
    seq = []
    for i in fbase: seq.append(number.pop(i))
    return seq

def permindex(seq, n=9):
    k = 1
    number = list(range(n))
    for i in range(n):
        f = factorial(n-i-1)
        k+= f*number.index(seq[i])
        number.remove(seq[i])
    return k

def adj(pi):
    def switch(i, j):
        p[i], p[j] = p[j], p[i]
        yield permindex(p)
        p[i], p[j] = p[j], p[i]
    p = kthperm(pi)
    zero = p.index(0)
    if zero >= 3: yield from switch(zero-3, zero)
    if zero <= 5: yield from switch(zero+3, zero)
    if zero%3 != 0: yield from switch(zero-1, zero)
    if zero%3 != 2: yield from switch(zero+1, zero)

puzzle = (input()+' '+input()+' '+input()).split()
puzzle = list(map(int, puzzle))
pi = permindex(puzzle)
visit = [-1]*362881
visit[pi] = 0
Q = deque()
Q.append(pi)

while len(Q):
    i = Q.popleft()
    if i == 46234:
        print(visit[i])
        break
    for j in adj(i):
        if visit[j] != -1: continue
        visit[j] = visit[i]+1
        Q.append(j)
else: print(-1)