import sys

sys.stdin = open("problem2_input.txt")

def getsum(s1, s2, g):
    global max_ans
    area = [0, 0, 0, 0, 0, 0]
    t = 0
    garo = [0, g+1, N]
    sero = [0, s1+1, s2+1, M]
    while t < 6:
        for i in range(2):
            for j in range(3):
                for x in range(garo[i], garo[i+1]):
                    for y in range(sero[j], sero[j+1]):
                        area[t] += field[x][y]
                t += 1
    big = max(area)
    small = min(area)
    result = abs(big-small)*2
    if result > max_ans:
        max_ans = result


testcase = int(input())

for tc in range(1, testcase + 1):
    N, M = map(int, input().split())
    field = [list(map(int, input().split())) for _ in range(N)]
    max_ans = 0
    # 세로줄 2개 => 가로줄 1개 => 함수
    for sero1 in range(M-2):
        for sero2 in range(sero1+1, M-1):
            for garo in range(N-1):
                getsum(sero1, sero2, garo)
    print("#{} {}".format(tc, max_ans))
