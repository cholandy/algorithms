for test in range(int(input())):
    n = int(input())
    coin = list(map(int, input().split()))
    target = int(input())
    dp = [[0 for i in range(n)] for j in range(target+1)]
    dp[0][0] = 1

    for i in range(1,target+1):
        for j in range(n):
            for k in range(j+1):
                dp[i][j] += dp[i-coin[j]][k]

    print(sum(dp[target]))
