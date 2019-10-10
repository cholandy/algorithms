import sys
sys.stdin = open('input.txt', 'r')

for _ in range(int(input())):
    ans = 0
    N, K = map(int, input().split())
    # print(N, K)
    mat = [list(map(int, input().split())) for _ in range(N)]
    # [print(*i) for i in mat]
    for i in range(N):
        for j in range(N):
            if mat[i][j]:
                # 가로로
                if j+K <= N and 0 <= i < N:
                    flag = True
                    for k in range(j, j+K):
                        if mat[i][k] == 0:
                            flag = False
                            break
                    if flag:
                        if j+K == N:
                            ans += 1
                            continue
                        if j == 0 and mat[i][j+K] != 1:
                            ans += 1
                            continue
                        if j-1 > -1 and mat[i][j-1] != 1 and j+K < N - 1 and mat[i][j+K] != 1:
                            ans += 1
                # 세로로
                if i+K <= N and 0 <= j < N:
                    flag = True
                    for k in range(i, i+K):
                        if mat[k][j] == 0:
                            flag = False
                            break
                    if flag:
                        if i == 0 and mat[i+K][j] != 1:
                            ans += 1
                            continue
                        if i+K == N:
                            ans += 1
                            continue
                        if i-1 > -1 and mat[i-1][j] != 1 and i+K < N-1 and mat[i+K][j] != 1:
                            ans += 1
    print("#{} {}".format(_+1, ans))
