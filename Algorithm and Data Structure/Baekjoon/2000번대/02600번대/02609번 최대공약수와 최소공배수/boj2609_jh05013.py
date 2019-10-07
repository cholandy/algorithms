def gcd(a,b):
    if a<b:
        return gcd(b,a)
    if b==0:
        return a
    return gcd(b,a%b)

a,b=map(int,input().split())
g=gcd(a,b)
print(g)
print(a*b//g)