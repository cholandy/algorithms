MIS = lambda: map(int,input().split())
n, m = MIS()
mem = list(MIS())
cost = list(MIS())

S = sum(cost)
dp = [0]*(S+1)
# first _ apps, cost j
for i in range(n):
    newdp = dp[:]
    for j in range(S+1):
        jc = j+cost[i]
        if jc <= S: newdp[jc] = max(newdp[jc], dp[j]+mem[i])
    dp = newdp
for i in range(S+1):
    if dp[i] >= m: print(i); break