import sys;sys.stdin=open('input2.txt','r')


def cal(temp):
    ret = 0
    for i in range(1, (1 << M)):
        tsum = 0
        ttsum = 0
        for j in range(0, M):
            if i & (1 << j):
                tsum += temp[j]
                ttsum += temp[j]**2
        if tsum <= C and ret < ttsum: ret = ttsum
 
    return ret
 
 
for tc in range(1, int(input()) + 1):
    N, M, C = list(map(int, input().split()))
    mat = [0] * N
    for i in range(N):
        mat[i] = list(map(int, input().split()))
 
    matt = [[0] * N for i in range(N)]
    for i in range(N):
        for j in range(N - M + 1):
            matt[i][j] = cal(mat[i][j:j + M])
 
    mattt = []
    for i in range(N):
        for j in range(N):
            mattt.append(matt[i][j])
 
    ans = 0
    for i in range(len(mattt) - M):
        for j in range(i + M, len(mattt)):
            if ans < mattt[i] + mattt[j]:
                ans = mattt[i] + mattt[j]
 
    print("#%d"%tc, ans)