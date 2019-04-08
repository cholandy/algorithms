import sys;sys.stdin=open('input1.txt','r')
import time
from itertools import combinations
start=time.time()
## 박보윤꺼
def killEnemy(x, y, D):
    global N, M
    distance = N*M
    for j in range(M):
        for i in range(x):
            if fight[i][j] == 1 and (abs(i-x)+abs(j-y) <= D):
                if distance > (abs(i-x)+abs(j-y)):
                    distance = abs(i-x)+abs(j-y)
                    ans = i, j
    if distance == N*M:
        return False
    else:
        return ans

for tc in range(int(input())):
    N, M, D = map(int, input().split())
    fight = []
    for _ in range(N):
        fight.append(list(map(int, input().split())))
    fight.append([0]*M)
    maxkill = 0
    for comb in combinations(range(M), 3):
        kill = 0
        a = [N, comb[0]]
        b = [N, comb[1]]
        c = [N, comb[2]]
        killedList = []
        for times in range(N):
            ae = killEnemy(a[0], a[1], D)
            be = killEnemy(b[0], b[1], D)
            ce = killEnemy(c[0], c[1], D)
            if ae != False:
                if fight[ae[0]][ae[1]] == 1:
                    fight[ae[0]][ae[1]] = 0
                    kill += 1
                    killedList.append([ae[0], ae[1]])
            if be != False:
                if fight[be[0]][be[1]] == 1:
                    fight[be[0]][be[1]] = 0
                    kill += 1
                    killedList.append([be[0], be[1]])
            if ce != False:
                if fight[ce[0]][ce[1]] == 1:
                    fight[ce[0]][ce[1]] = 0
                    kill += 1
                    killedList.append([ce[0], ce[1]])
            a[0] -= 1
            b[0] -= 1
            c[0] -= 1
        if maxkill < kill:
            maxkill = kill
        for k in killedList:
            fight[k[0]][k[1]] = 1
    print(maxkill)
finish=time.time()
print(finish-start)