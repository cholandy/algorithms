import sys
input=sys.stdin.readline
n,m=map(int,input().split())
d=[]
for i in range(int(input())):
    d.append(list(map(int,input().split())))
x,y=map(int,input().split())
r=0
for a in d:
    u,v=a
    if x==u:
    	r+=abs(y-v)
    elif x*u==2:
        r+=m+min(y+v,n+n-y-v)
    elif x*u==12:
        r+=n+min(y+v,m+m-y-v)
    elif u>=3:
        if u==3:
            r+=y
        else:
            r+=n-y
        if x==1:
            r+=v
        else:
            r+=m-v
    else:
        if u==1:
            r+=y
        else:
            r+=m-y
        if x==3:
            r+=v
        else:
            r+=n-v
print(r)