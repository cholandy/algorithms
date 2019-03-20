for tc in range(int(input())):
    n=int(input())%1000000007
    if n==1:
        print(2)
        continue
    a,b,r=1,0,0
    while b!=n:
        a,b=b,(a+b)%1000000007
        r+=1
    print(r)