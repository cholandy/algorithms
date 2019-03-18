a,b,c=map(int,input().split())
if c:
    c-=1
    r=1
    for i in range(c//b+c%b):
        r*=i+1
    for i in range(c//b):
        r//=i+1
    for i in range(c%b):
        r//=i+1
    for i in range(a+b-c//b-c%b-2):
        r*=i+1
    for i in range(a-c//b-1):
        r//=i+1
    for i in range(b-c%b-1):
        r//=i+1
else:
    r=1
    for i in range(a+b-2):
        r*=i+1
    for i in range(a-1):
        r//=i+1
    for i in range(b-1):
        r//=i+1
print(r)