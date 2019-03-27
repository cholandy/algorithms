def ncm(n,m):
    cur = 1
    for i in range(1,m+1):
        cur = cur*(n-i+1)//i
    return cur
a,b,c = map(int,input().split())
if c != 0:
    y,x = divmod(c-1,b)
    print(ncm(x+y,y)*ncm(a+b-x-y-2,a-y-1))
else:
    print(ncm(a+b-2,b-1))