from fractions import gcd
a,b = map(int, input().split(":"))
g = gcd(a,b)
a//=g
b//=g
print("%d:%d"%(a,b))