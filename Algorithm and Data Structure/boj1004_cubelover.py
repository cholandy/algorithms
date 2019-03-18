for tc in range(int(input())):
    a,b,c,d=map(int,input().split())
    t=0
    for i in range(int(input())):
        x,y,r=map(int,input().split())
        t+=((a-x)**2+(b-y)**2<r*r)!=((c-x)**2+(d-y)**2<r*r)
    print(t)