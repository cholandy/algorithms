from fractions import gcd
from functools import reduce

n, k = map(int,input().split())
angle = [360]+list(map(int,input().split()))
G = reduce(gcd, angle)
for a in map(int,input().split()):
    print("YES" if a%G==0 else "NO")