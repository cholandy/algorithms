import sys
sys.setrecursionlimit(1000000000)

arr = sys.stdin.readline()
n = len(arr)-1

dp = [0]*(n)
dp[0] = 1
chk = [[0]*(n) for i in range(n)]

chk[n-1][n-1] = 1
for i in range(n-1):
	chk[i][i] = 1
	if arr[i] == arr[i+1]:
		chk[i][i+1] = 1

for k in range(3, n+1):
	for i in range(n-k +1):
		j = i+k-1
		if arr[i] == arr[j] and chk[i+1][j-1]:
			chk[i][j] = 1

for i in range(n):
	for j in range(i +1):
		if chk[j][i]:
			if dp[i]==0 or (dp[i]>dp[j-1]+1):
				dp[i] = dp[j-1]+1
print(dp[n-1])
