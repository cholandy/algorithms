def gcd(a,b):
    if a<b:
        return gcd(b,a)
    if b==0:
        return a
    return gcd(b,a%b)

for T in range(int(input())):
    a, b = map(int,input().split())
    print(a*b//gcd(a,b))