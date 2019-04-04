def find(k, pcnt):
    t0 = [0]*100 #0번 식당까지 도착 시간별 인원 저장용
    t1 = [0]*100 #1번 식당까지 도착 시간별 인원 저장용
    for i in range(pcnt): # i사람의 계단까지 거리 + 대기시간 1초
        if k&(1<<i) == 0:
            t0[dis[i][0]+1] += 1
        else:
            t1[dis[i][1]+1] += 1
    # 시간별 계단에 있는 인원
    sta0 = [0]*200
    sta1 = [0]*200
    last0 = 0 # 마지막 사람이 계단을 통과한 시간
    last1 = 0 # 마지막 사람이 계단을 통과한 시간
    for i in range(99):
        if(t0[i]!=0): # 0번 입구에 도착 인원이 있으면
            if(sta0[i]+t0[i]>3): # 초과 인원은 다음 타임으로 넘김
                rest = sta0[i]+t0[i]-3
                t0[i+1] += rest
                t0[i] -= rest
            j = 0
            while(j<cafe[0][2]): # 계단 통과 시간 동안 인원 기록
                sta0[i+j] += t0[i]
                last0 = i+j
                j += 1
                  
        if(t1[i]!=0): # 0번 입구에 도착 인원이 있으면
            if(sta1[i]+t1[i]>3): # 초과 인원은 다음 타임으로 넘김
                rest = sta1[i]+t1[i]-3
                t1[i+1] += rest
                t1[i] -= rest   
            j = 0
            while(j<cafe[1][2]): # 계단 통과 시간 동안 인원 기록
                sta1[i+j] += t1[i]
                last1 = i+j
                j += 1
  
    return max(last0, last1)+1
  
T = int(input())
for tc in range(1, T+1):
    N = int(input())
    m = [list(map(int, input().split())) for i in range(N)]
    person = []
    pcnt = 0
    cafe = []
  
    for i in range(N):
        for j in range(N):
            if m[i][j] == 1:
                pcnt += 1
                person.append([i,j])
            elif m[i][j] != 0:
                cafe.append([i,j,m[i][j]])
    dis = [[0]*2 for i in range(pcnt)]
    for i in range(pcnt):
        dis[i][0] = abs(person[i][0]-cafe[0][0])+abs(person[i][1]-cafe[0][1]) # 사람i -> 식당0 거리
        dis[i][1] = abs(person[i][0]-cafe[1][0])+abs(person[i][1]-cafe[1][1]) # 사람i -> 식당1 거리
    minT = 1000000
    for k in range(1<<pcnt): # i사람이 간 식당을 i번 비트로 표시
        r = find(k, pcnt) # 시간 계산
        if (minT > r):
            minT = r
    print(f'#{tc} {minT}')