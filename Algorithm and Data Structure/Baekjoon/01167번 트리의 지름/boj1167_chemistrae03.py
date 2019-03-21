import sys
sys.setrecursionlimit(10**9)
n=int(input())
INF=10e9
t=[[] for _ in range(n+1)]
u,ld=0,0
def dfs(h,d):
 global di,ld,u;di[h]=d
 if di[h]>ld:ld=di[h];u=h
 for i in t[h]:
  if di[i[0]]==INF: dfs(i[0],d+i[1])
for _ in range(n):
 s=list(map(int,input().split()));s.pop(len(s)-1)
 for i in range(1,len(s),2):t[s[0]].append((s[i],s[i+1]));t[s[i]].append((s[0],s[i+1]))
di=[INF for _ in range(n+1)]
dfs(1,0)
di=[INF for _ in range(n+1)]
dfs(u,0)
print(ld)