while 1:
    n,m = map(int,input().split())
    if n==m==0:
        break
    if 2*m > n:
        m = n-m
    cur = 1
    for i in range(1,m+1):
        cur = cur*(n-i+1)//i
    print(cur)