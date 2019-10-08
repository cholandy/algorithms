r,c,m = map(int, input().split())
info = [0 for i in range(m)]
position = [[0 for i in range((r-1)*2)],
            [0 for i in range((c-1)*2)]]
for i in range((r-1)*2):
    if i <= r-1:
        position[0][i] = i
    else:
        position[0][i] = position[0][i-1] -1
for i in range((c-1)*2):
    if i <= c-1:
        position[1][i] = i
    else:
        position[1][i] = position[1][i-1] -1


for i in range(m):
    x,y,s,d,z = map(int, input().split())

    if d == 2:
        idx = x-1
    elif d == 3:
        idx = y-1
    elif d == 1:
        idx = (r-1) + (r-1-(x-1))
    else:
        idx = (c - 1) + (c - 1 - (y-1))
    info[i] = [x - 1, y - 1, s, d, z, idx]
# r,c,s,d,z : 상어의 위치 / 속력/이동 방향/크기
# d: 1- 위, 2- 아래, 3- 오른쪽, 4 - 왼쪽
# 낚시왕이 잡은 상어 크기의 합 출력하기
# info 행 뒤에 position 리스트 상의 인덱스를 추가한다

# print(position)
# print(info)

total = 0
for t in range(c):
    # 땅과 가장 가까이에 있는 상어 잡기
    idx = int(1e9)
    erase= int(1e9)
    for i in range(m):
        if info[i][1] == t and info[i][0] != float(1e-9) and idx > info[i][0]:
            idx = info[i][0]
            erase = i
    if idx != int(1e9):
        info[erase][0] = float(1e-9)
        total += info[erase][4]

    visited = [[-1 for i in range(c)] for i in range(r)]
    # print(t, erase,info)
    # 상어가 이동한다
    for i in range(m):
        if info[i][0] != float(1e-9):
            if info[i][3] == 1 or info[i][3] == 2:
                info[i][5] = (info[i][5]+info[i][2]) % ((r-1)*2)
                info[i][0] = position[0][info[i][5]]
            else:
                info[i][5] = (info[i][5]+info[i][2]) % ((c-1)*2)
                info[i][1] = position[1][info[i][5]]
            if visited[info[i][0]][info[i][1]] == -1:
                visited[info[i][0]][info[i][1]] = i
            else:
                temp = visited[info[i][0]][info[i][1]]
                if info[temp][4] > info[i][4]:
                    info[i][0] = float(1e-9)
                else:
                    info[temp][0] = float(1e-9)
                    visited[info[i][0]][info[i][1]] = i
    # print(t, info)
    # print(33333333333,visited)
print(total)