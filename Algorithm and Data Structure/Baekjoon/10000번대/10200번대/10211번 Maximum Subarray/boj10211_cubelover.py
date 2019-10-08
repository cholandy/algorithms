import sys
input=sys.stdin.readline
for tc in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=0
    m=0
    r=a[0]
    for i in range(n):
        s+=a[i]
        r=max(r,s-m)
        m=min(m,s)
    print(r)