import sys;sys.stdin=open('input1.txt','r')
import itertools
from time import time

a=time()
## 전세환꺼

def defence_castle(archers):
    global max_kill, N, M, D, max_step
    kill = 0
    # target은 병졸 idx, 거리, column좌표 저장
    target = [[-1, D, M], [-1, D, M], [-1, D, M]]
    # 병사는 최대 전진수만큼 반복
    for step in range(max_step):
        # 전진한 결과 성벽을 통과한 병사는 그냥 죽은 것으로 처리
        for enemy in enemies:
            if enemy[2] is False and (enemy[0] + step) >= N:
                enemies[enemy[3]][2] = True

        # 궁수의 표적 설정
        for enemy in enemies:
            # 병졸이 살아있을 때만 표적취급
            if enemy[2] is False:
                # 3 궁수에 대해서 거리 계산
                for a in range(3):
                    distance = abs(enemy[0] + step - N) + abs(enemy[1] - archers[a])
                    if distance < target[a][1]:
                        target[a] = [enemy[3], distance, enemy[1]]
                    elif distance == target[a][1] and enemy[1] < target[a][2]:
                        target[a] = [enemy[3], distance, enemy[1]]

        # 표적 설정이 끝났으면 일제 사격
        for t in target:
            # 해당 표적이 존재하며 생존 상태일 때만 저격횟수 증가
            if t[0] != -1 and enemies[t[0]][2] is False:
                enemies[t[0]][2] = True
                kill += 1
        # 일제 사격 후 표적 설정 초기화
        target = [[-1, D, M], [-1, D, M], [-1, D, M]]

    # 최종 저격횟수 구했으면 갱신 시도
    if kill > max_kill:
        max_kill = kill

for tc in range(int(input())):
    N, M, D = map(int, input().split())
    field = [list(map(int, input().split())) for _ in range(N)]

    # 적의 병졸 정보를 따로 저장
    # enemies = [row, col, death, index]
    enemies = []
    idx = 0
    for r in range(N):
        for c in range(M):
            if field[r][c] == 1:
                enemies.append([r, c, False, idx])
                idx += 1
    people = enemies[-1][-1] + 1
    max_step = N - enemies[0][0] + 1

    # 조합을 이용해 궁수 배치후 사격 함수 돌리기
    max_kill = 0
    for combi in itertools.combinations(range(M), 3):
        # 이미 전원 처치한 기록 있으면 중단
        if max_kill == people:
            break
        # 함수 돌리기 전, 적을 모두 생존상태로 초기화
        for _ in range(people):
            enemies[_][2] = False
        defence_castle(combi)

    print(max_kill)
b=time()

print(b-a)