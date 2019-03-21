import sys,collections
from heapq import heappush,heappop
INF=2**20
sys.setrecursionlimit(INF)
input=sys.stdin.readline
def djk():
    cs=[INF for _ in range(n)];cs[s]=0
    pq=[(0,s)]
    while pq:
        c,h=pq[0];heappop(pq)
        if cs[h]<c:continue
        for i in tre[h]:
            nc= c + tre[h][i]
            if cs[i]>nc:
                cs[i]=nc
                heappush(pq,(nc,i))
                trc[i]=[h]
            if cs[i]==nc:trc[i].append(h)
    return cs[e]
while True:
    n,m=map(int,input().split())
    if n==0:break
    s,e=map(int,input().split())
    tre=[{} for _ in range(n)]
    trc = [[] for _ in range(n)]
    vi=[[False for _ in range(n)] for _ in range(n)]
    for i in range(m):
        u,v,p=map(int,input().split())
        tre[u][v]=p
    djk()
    q=collections.deque([e])
    while q:
        h=q[0];q.popleft()
        for i in trc[h]:
            if vi[h][i]:continue
            vi[h][i]=True
            tre[i].pop(h)
            q.append(i)
    ret=djk()
    if ret==INF:print(-1)
    else:print(ret)
