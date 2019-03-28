import sys;sys.stdin=open('input2.txt','r')

def tsp(now, next): # now=현재, next=다음
    ret = dp[now][next]
    res = float('INF')
    if next == all: # 만약 마지막 고객까지 끝냈으면 
        return dist[now][N+1] # 그 고객에서부터 집가지의 거리를 반환
    if ret != 0: # 이미 방문했다면 넘어간다
        return ret
    for i in range(1, N+1): # 1번 고객부터 N번 고객까지. 
        if next&(1<<i) == 0: # 만약 i번 고객을 방문하지 않았다면
            # i번 고객을 방문 표시하고 다시 내려감.              
            res = min(res , tsp(i,next|(1<<i))+dist[now][i]) 
            # 반환값+현재고객에서 다음 고객까지의 거리
            # 반환값은 항상 최소값으로 돌아옴
    dp[now][next] = res #dp에 현재 방문한 인원까지 순회한 가장 짧은 거리를 저장
    return res


for tc in range(int(input())):
    N = int(input())
    coor = list(map(int, input().split()))
    comp,home=[coor[0],coor[1]],[coor[2],coor[3]]
    gps=[comp]+[[coor[i],coor[i+1]] for i in range(4,len(coor),2)]+[home]
    dp = [[0]*(1<<N+1) for _ in range(N+1)] # dp용 배열
    dist = [[0]*(N+2) for _ in range(N+2)] # 각 노드간 거리를 저장할 배열
    all = (1<<N+1) - 1 
    for i in range(N+2):
        for j in range(N+2):
            dist[i][j] = abs(gps[i][0]-gps[j][0]) + abs(gps[i][1]-gps[j][1])
    
    print(f'#{tc+1} {tsp(0, 1)}') # tsp(현재 고객 0명, 회사에서 출발)