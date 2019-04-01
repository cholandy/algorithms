for tc in range(int(input())):
    n,m=map(int,input().split())
    d=[0 for i in range(m+1)]
    for i in range(2,n+1):
        d[i]=min(d[i-1]+1,d[i-1]+10,d[i-1]-1)
        if i%2==0:
            d[i]=min(d[i],d[i//2]+1)
    print(d[m]-d[n])
    