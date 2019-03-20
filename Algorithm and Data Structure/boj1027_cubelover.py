n=int(input())
a=list(map(int,input().split()))
d=[0]*n
for i in range(n):
  for j in range(i):
    f=1
    for k in range(j+1,i):
      if (k-j)*a[i]+(i-k)*a[j]<=(i-j)*a[k]:
        f=0
    if f:
      d[i]+=1
      d[j]+=1
print(max(d))