n=int(input())
a=[input() for i in range(n)]
d=[0]*n
for i in range(n):
  for j in range(n):
    if i!=j:
      f=0
      if a[i][j]=='Y':
        f=1
      for k in range(n):
        if a[i][k]=='Y' and a[j][k]=='Y':
          f=1
      if f:
        d[i]+=1
print(max(d))