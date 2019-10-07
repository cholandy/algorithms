from fractions import gcd
a,b=map(int,input().split())
g=gcd(a,b)
i=1
while i*i<g:
    if g%i==0:
        print("%d %d %d"%(i,a//i,b//i))
    i+=1
if i*i==g:
    print("%d %d %d"%(i,a//i,b//i))
while i>1:
    i-=1
    if g%i==0:
        print("%d %d %d"%(g//i,a*i//g,b*i//g))