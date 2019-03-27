for tc in range(int(input())):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    r=1
    while True:
        if a[0]!=max(a):
            a.append(a[0])
        elif m==0:
            break
        else:
            r+=1
        del a[0]
        m-=1
        if m<0:
            m+=len(a)
    print(r)