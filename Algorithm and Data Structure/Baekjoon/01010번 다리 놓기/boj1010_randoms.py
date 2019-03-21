def f(n,k):
    r=1
    for i in range(k):
        r*=(n-i)
        r//=(i+1)
    return r
for _ in range(int(input())):
    k,n=map(int,input().split())
    print(f(n,k))