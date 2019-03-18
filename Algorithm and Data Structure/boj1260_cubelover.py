n,m,l=map(int,input().split())
g=[[0]*n for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  g[a-1][b-1]=g[b-1][a-1]=1
def f(x):
  global n,g,v,r
  if v[x]:
    return
  v[x]=1
  r.append(x+1)
  for i in range(n):
    if g[x][i]:
      f(i)
v=[0]*n
r=[]
f(l-1)
print(' '.join(map(str,r)))
v=[0]*n
v[l-1]=1
q=[l]
for x in q:
  for i in range(n):
    if g[x-1][i] and not v[i]:
      v[i]=1
      q.append(i+1)
print(' '.join(map(str,q)))