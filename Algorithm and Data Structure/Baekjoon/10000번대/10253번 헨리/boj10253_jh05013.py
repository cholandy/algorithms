from fractions import Fraction
from math import ceil

for T in range(int(input())):
    a, b = map(int,input().split())
    f = Fraction(a,b)
    last = b
    while f:
        x = ceil(1/f)
        last = x
        f-= Fraction(1,x)
    print(last)