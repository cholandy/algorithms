import sys;sys.stdin=open('input1.txt','r')

T = int(input())+1
for tc in range(1,T):
    N = int(input())
    arr = [list(map(int, input().split())) for i in range(N)]
 
    queue = []
    e = []
    for i in range(N):
        for j in range(N):
            if arr[i][j] == 1:
                queue.append([i, j])
            if arr[i][j] > 1:
                e.append([i, j, arr[i][j]])
    D = []
 
    for j in queue:
        a = []
        for i in e:
            dis = abs(i[0] - j[0]) + abs(i[1] - j[1]) + 1
            a.append(dis + i[2])
        D.append(a)
 
    res = []
    r1 = 0
    r2 = 0
    m_i = 0
    for i in D:
        if i[0] < i[1]:
            r1 += 1
            res.append([i[0], 1, m_i])
        else:
            r2 += 1
            res.append([i[1], 2, m_i])
        m_i += 1
    res.sort()
    for i in res:
        if r1 > 3:
            i[0] = min(i[0] + e[0][2], D[i[2]][1])
            r1 -= 1
        if r2 > 3:
            i[0] = min(i[0] + e[1][2], D[i[2]][0])
            r2 -= 1
    r = 0
    for i in res:
        r = max(i[0], r)
    print("#{} {}".format(tc,r))