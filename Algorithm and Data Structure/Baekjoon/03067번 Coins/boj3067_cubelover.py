for tc in range(int(input())):
    n=int(input())
    a=map(int,input().split())
    m=int(input())
    d=[0 for i in range(m+1)]
    d[0]=1
    for x in a:
        for i in range(x,m+1):
            d[i]+=d[i-x]
    print(d[m])