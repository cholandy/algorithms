n,m=map(int,input().split())
x=y=1111
for i in range(m):
    a,b=map(int,input().split())
    x=min(x,a)
    y=min(y,b)
print(min(n*y,n//6*x+n%6*y,(n+5)//6*x))