def tsp(cur,stat):
    if stat == all:
        return dist[cur][cn+1]
    ret = dp[cur][stat]
    if ret != 0:
        return ret
    m = 987654321
    for i in range(1,cn+1):
        if stat&(1<<i) == 0:
            m = min(m, tsp(i,stat|(1<<i)) + dist[cur][i])
    dp[cur][stat] = m
    return m
     
 
for t in range(int(input())):
    cn = int(input())
    lis = list(map(int,input().split()))
    xy = [0]*(cn+2)
    xy[0] = [lis[0],lis[1]]
    n = 1
    for i in range(4,len(lis),2):
        xy[n] = [lis[i],lis[i+1]]
        n += 1
    xy[n] = [lis[2],lis[3]]
    dp = [[0]*(1<<(cn+1)) for _ in range(cn+2)]
    dist = [[0]*(cn+2) for _ in range(cn+2)]
    all = (1<<cn+1)-1
    for i in range(cn+2):
        for j in range(cn+2):
            dist[i][j] = abs(xy[i][0] - xy[j][0])+abs(xy[i][1]-xy[j][1])
 
    print(f'#{t+1} {tsp(0,1)}')