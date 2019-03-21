a=100
b=100
for i in range(int(input())):
    x,y=map(int,input().split())
    if x<y:
        a-= y
    elif x>y:
        b-= x
print(a)
print(b)