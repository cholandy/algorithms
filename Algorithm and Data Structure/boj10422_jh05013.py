from functools import reduce
def ncr(n, r):
    return reduce(lambda x, y: x*y[0]//y[1], zip(range(n-r+1, n+1), range(1, r+1)), 1)

def catalan(n):
    return ncr(2*n, n)//(n+1)

for T in range(int(input())):
    a = int(input())
    if a%2 == 1:
        print(0)
    else:
        print(catalan(a//2)%1000000007)