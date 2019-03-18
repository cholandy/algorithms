for tc in range(int(input())):
    a,b,c,d,e,f=map(int,input().split())
    if a==d and b==e and c==f:
        print(-1)
        continue
    p=(a-d)**2+(b-e)**2
    q=(c+f)**2
    r=(c-f)**2
    print((p<=q)+(p<q)-(p<=r)-(p<r))