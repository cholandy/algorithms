a=input()
n=len(a)
d=[0 for i in range(10)]
for i in range(n):
    d[ord(a[i])-48]+=1
d[6]+=d[9]
d[9]=0
r=0
for i in range(10):
    if i==6:
        r=max(r,(d[i]+1)//2)
    else:
        r=max(r,d[i])
print(r)