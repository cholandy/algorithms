N=int(input())
dp=[[0]*N for _ in range(N)]
dp[0][0]=1
for j in range(N):
	for i,k in enumerate(map(int,input().split())):
		if k>0:
			if j+k<N:dp[j+k][i]+=dp[j][i]
			if i+k<N:dp[j][i+k]+=dp[j][i]
print(dp[-1][-1])