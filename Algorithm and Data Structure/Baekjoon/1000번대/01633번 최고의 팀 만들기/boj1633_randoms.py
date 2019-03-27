import sys
s=sys.stdin.readlines()
L=[list(map(int,i.split()))for i in s]
N=len(L)
DP=[[[0for k in range(17)]for j in range(17)]for i in range(N+1)]
for i in range(N):
    for j in range(16):
        for k in range(16):
            DP[i+1][j][k]=max(DP[i+1][j][k],DP[i][j][k])
            DP[i+1][j+1][k]=max(DP[i+1][j+1][k],DP[i][j][k]+L[i][0])
            DP[i+1][j][k+1]=max(DP[i+1][j][k+1],DP[i][j][k]+L[i][1])
print(DP[-1][15][15])