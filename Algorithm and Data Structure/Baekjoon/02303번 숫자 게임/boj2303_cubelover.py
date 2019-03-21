mx=mxi=0
for i in range(int(input())):
    a=list(map(int,input().split()))
    t=0
    for j in range(5):
        for k in range(j):
            for l in range(k):
                t=max(t,(a[j]+a[k]+a[l])%10)
    if t>=mx:
        mx=t
        mxi=i
print(mxi+1)