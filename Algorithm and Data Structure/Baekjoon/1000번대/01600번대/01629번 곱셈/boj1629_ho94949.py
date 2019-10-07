a,b,c=list(map(int,input().split()))
d = a
a = 1
while b!=0:
    if b%2==1: 
        a = (a*d)%c
    d = (d*d)%c
    b//=2
print(a%c)