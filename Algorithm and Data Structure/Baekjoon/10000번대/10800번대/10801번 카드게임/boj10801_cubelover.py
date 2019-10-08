a=list(map(int,input().split()))
b=list(map(int,input().split()))
r=0
for i in range(10):
    if a[i]>b[i]:
        r+=1
    if a[i]<b[i]:
        r-=1
if r>0:
    print("A")
elif r<0:
    print("B")
else:
    print("D")