from fractions import gcd
R,G = map(int,input().split())
g = gcd(R,G)
largediv = []

for i in range(1,int(g**0.5)+1):
    if g%i==0:
        largediv.append(g//i)
        print("%d %d %d"%(i, R//i, G//i))
if largediv[-1]**2 == g:
    largediv.pop()
for i in range(len(largediv)-1,-1,-1):
    d = largediv[i]
    print("%d %d %d"%(d, R//d, G//d))