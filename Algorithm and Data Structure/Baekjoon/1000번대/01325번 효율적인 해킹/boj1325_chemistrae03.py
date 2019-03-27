import sys
import collections
input=sys.stdin.readline
f=lambda:map(int,input().rstrip().split())
n,m=f()
t=[[] for _ in range(n+1)]
v=[]
r=[]
for i in range(m):a,b=f();t[b].append(a)
def bfs(s):
 c=1;v[s]=1;q=collections.deque([s])
 while q:
  h=q[0];q.popleft()
  for i in t[h]:
   if not v[i]:q.append(i);v[i]=1;c+=1
 return c
for i in range(n):v=[0]*(n+1);r.append(bfs(i+1))
ma=max(r)
for i in range(n):
 if r[i]==ma: print(i+1)