d=[1]*246913
d[0]=d[1]=0
for i in range(2,246913):
    if d[i]:
        j=i+i
        while j<246913:
            d[j]=0
            j+=i
for i in range(1,246913):
    d[i]+=d[i-1]
while True:
    n=int(input())
    if n==0:
        break
    print(d[n+n]-d[n])