import sys;sys.stdin=open('input.txt','r')

def tsp(cur, stat):
    res = float('INF')
    ret = dp[cur][stat]
    if stat == all: return dist[cur][N+1]
    if ret != 0: return ret
    for i in range(1, N+1):
        if stat&(1<<i) == 0:
            res = min(res, tsp(i,stat|(1<<i))+dist[cur][i])
    dp[cur][stat] = res
    return res


for tc in range(int(input())):
    N = int(input()) # 고객 수
    # - - - - - - - - - - 인풋 데이터 전처리 - - - - - - - - - - - - - - #
    coor = list(map(int, input().split()))
    comp,home=[coor[0],coor[1]],[coor[2],coor[3]]
    gps=[comp]+[[coor[i],coor[i+1]] for i in range(4,len(coor),2)]+[home]
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
    dp = [[0]*(1<<N+1) for _ in range(N+2)] # 각 행마다 0이 2**(N+1)만큼 있음. 
    dist = [[0]*(N+2) for _ in range(N+2)]
    all = (1<<N+1) - 1 # 원소가 N+1개인 집합의 부분집합의 갯수 -1(공집합 제외)
    for i in range(N+2):
        for j in range(N+2):
            dist[i][j] = abs(gps[i][0] - gps[j][0]) + abs(gps[i][1] - gps[j][1])
#     for i in dist:print(*i)
#     print()
    print(f'#{tc+1} {tsp(0,1)}')
    for i in dp:print(*i)