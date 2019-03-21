def f(x,y):
    z=0
    while x:
        x,z=x//y,z*y+x%y
    return z
for tc in range(int(input())):
    n=int(input())
    r=0
    for i in range(2,65):
        if n==f(n,i):
            r=1
    print(r)