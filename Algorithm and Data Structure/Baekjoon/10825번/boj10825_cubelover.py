n=int(input())
a=[]
for i in range(n):
    w,x,y,z=input().split()
    a.append((-int(x),int(y),-int(z),w))
a.sort()
for i in range(n):
    print(a[i][3])