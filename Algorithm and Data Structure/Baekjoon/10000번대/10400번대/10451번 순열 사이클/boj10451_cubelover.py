for tc in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    d=[0]*n
    r=0
    for i in range(n):
        if d[i]==0:
            r+=1
            j=i
            while d[j]==0:
                d[j]=1
                j=a[j]-1
    print(r)