n,m=map(int,input().split())
a=[]
for i in range(n):
    w,x,y,z=input().split()
    a.append((-int(y),int(z),w,x))
a.sort()
b=set()
for w,x,y,z in a:
    if y not in b:
        m -= 1
        print(z)
        b.add(y)
    if not m:
        break