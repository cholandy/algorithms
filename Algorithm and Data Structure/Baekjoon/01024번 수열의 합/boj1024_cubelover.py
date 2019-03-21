n,m=map(int,input().split())
while m<=100:
  if m*(m-1)//2<=n and not (n-m*(m-1)//2)%m:
    break
  m+=1
if m>100:
  print(-1)
else:
  for i in range(m):
    print((n-m*(m-1)//2)//m+i,end=' ')