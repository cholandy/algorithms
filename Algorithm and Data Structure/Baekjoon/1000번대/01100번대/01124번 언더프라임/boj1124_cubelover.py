a,b=map(int,input().split())
def f(x):
    if x==1:
        return 0
    i=2
    while i*i<=x:
        if x%i==0:
            return 0
        i+=1
    return 1
def g(x):
    t=0
    i=2
    while i*i<=x:
        while x%i==0:
            t+=1
            x/=i
        i+=1
    if x>1:
        t+=1
    return f(t)
r=0
for i in range(a,b+1):
    r+=g(i)
print(r)