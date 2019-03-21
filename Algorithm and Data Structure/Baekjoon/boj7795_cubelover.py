from bisect import bisect_left
for tc in range(int(input())):
    n,m=map(int,input().split())
    a=map(int,input().split())
    b=sorted(map(int,input().split()))
    b.sort()
    r=0
    for x in a:
        r+=bisect_left(b,x)
    print(r)