N,K=map(int,input().split())
dp=[0]*(K+1)
notzerolist=[0]
for _ in range(N):
    at,av,bt,bv=map(int,input().split())
    nextlist=[]
    ndp=[0]*(K+1)
    notzero=[0]*(K+1)
    for i in notzerolist:
        if i+at<=K:
            ndp[i+at]=max(ndp[i+at],dp[i]+av)
            if not notzero[i+at]:
                nextlist.append(i+at)
                notzero[i+at]=1
        if i+bt<=K:
            ndp[i+bt]=max(ndp[i+bt],dp[i]+bv)
            if not notzero[i+bt]:
                nextlist.append(i+bt)
                notzero[i+bt]=1
    dp=ndp
    notzerolist=nextlist
print(max(dp))