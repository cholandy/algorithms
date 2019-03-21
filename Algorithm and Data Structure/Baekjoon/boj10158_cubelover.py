a,b=map(int,input().split())
c,d=map(int,input().split())
t=int(input())
c+=t
d+=t
c%=a+a
d%=b+b
if c>a:
    c=a+a-c
if d>b:
    d=b+b-d
print(c,d)