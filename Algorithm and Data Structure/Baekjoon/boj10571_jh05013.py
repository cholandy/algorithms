input = __import__('sys').stdin.readline
MFS = lambda: map(float,input().split())

for TEST in range(int(input())):
    n = int(input())
    gem = [tuple(MFS()) for i in range(n)]
    dp = [1]
    for i in range(1, n):
        x, y = gem[i]
        ans = 0
        for j in range(i):
            px, py = gem[j]
            if px < x and py > y: ans = max(ans, dp[j])
        dp.append(ans+1)
    #print(gem)
    #print(dp)
    print(max(dp))