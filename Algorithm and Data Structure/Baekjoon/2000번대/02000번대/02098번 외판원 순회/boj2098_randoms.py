N=int(input())
W=[list(map(int,input().split()))for i in range(N)]
DP=[[-1]*2**17 for i in range(N)]
INF=10000000
def update(p,n):
    global W,DP,N,INF
    if n==(1<<N)-1:
        return 0if p==0else INF
    if DP[p][n]>=0:
        return DP[p][n]
    ret=INF
    for i in range(N):
        if n&1<<i!=0 or W[p][i]==0:
            continue
        temp=W[p][i]+update(i,n+(1<<i))
        ret=min(ret,temp)
    DP[p][n]=ret
    return DP[p][n]
print(update(0,0))