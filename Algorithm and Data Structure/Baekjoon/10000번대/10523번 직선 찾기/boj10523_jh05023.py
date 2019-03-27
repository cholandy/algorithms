from sys import stdin
input = stdin.readline
n = int(input())
p = int(input())
target = 0.01*n*p
x = []
y = []
for i in range(n):
    a, b = map(int,input().split())
    x.append(a)
    y.append(b)

from random import randrange
def attempt():
    i = randrange(0, n-1)
    j = randrange(i+1, n)
    res = 0
    for k in range(n):
        if (y[j]-y[i])*(x[k]-x[j]) == (y[k]-y[j])*(x[j]-x[i]):
            res+= 1
    if res >= target:
        return True

if n == 1:
    print("possible")
    exit()
for trial in range(300):
    if attempt():
        print("possible")
        break
else:
    print("impossible")