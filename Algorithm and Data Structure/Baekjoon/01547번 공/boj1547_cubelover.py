t=1
for i in range(int(input())):
    a,b=map(int,input().split())
    if t==a:
        t=b
    elif t==b:
        t=a
print(t)