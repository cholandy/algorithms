import sys
input=sys.stdin.readline
for tc in range(4):
    a,b,c,d,e,f,g,h=map(int,input().split())
    if a<g and e<c:
        p=2
    elif a<=g and e<=c:
        p=1
    else:
        p=0
    if b<h and f<d:
        q=2
    elif b<=h and f<=d:
        q=1
    else:
        q=0
    if p==2 and q==2:
        print("a")
    elif p+q==3:
        print("b")
    elif p and q:
        print("c")
    else:
        print("d")