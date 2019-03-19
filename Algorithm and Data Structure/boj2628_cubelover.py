n,m=map(int,input().split())
a=[0,n]
b=[0,m]
for i in range(int(input())):
    x,y=map(int,input().split())
    if x:
        a.append(y)
    else:
        b.append(y)
a.sort()
b.sort()
print(max(a[i]-a[i-1] for i in range(1,len(a)))*max(b[i]-b[i-1] for i in range(1,len(b))))