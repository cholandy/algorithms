
from collections import deque
from itertools import combinations
from copy import deepcopy

MIS=lambda:map(int,input().split())

def nextattack(field):
    for i in range(H):
        if sum(field[i]):
            return 1
    return 0

def attackdistance(x,y):
    attack=[ [0]*W for _ in range(H)]
    for q in range(H):
        for w in range(W):
            if abs(x-q)+abs(y-w)>D:continue
            attack[q][w]=abs(q-x)+abs(w-y)
    return attack

H,W,D=MIS()
field=[list(MIS()) for _ in range(H)]
archer=[]
archer+=combinations(range(W),3)
answer=0
for archerindex in archer: 
    kill_point_of_this_place=0
    simulation_field=deepcopy(field)
    while nextattack(simulation_field):
        enemy=[]
        for h,i in zip([H]*3,archerindex):
            attack=attackdistance(h,i)      
            kill=deque()
            kill.append((h-1,i))
            while kill:
                key=0
                sx,sy=kill.popleft()
                if simulation_field[sx][sy]==1:
                    kill_point_of_this_place+=1
                    enemy.append((sx,sy))
                    simulation_field[sx][sy]+=1
                    break
                elif simulation_field[sx][sy]>1:
                    break
                for x,y in (0,-1),(-1,0),(0,1):
                    nx,ny=sx+x,sy+y
                    if 0<=nx<H and 0<=ny<W and attack[nx][ny]: 
                        attack[nx][ny]=0
                        if simulation_field[nx][ny]==0:
                            kill.append((nx,ny))
                        elif simulation_field[nx][ny]==1:
                            kill_point_of_this_place+=1
                            enemy.append((nx,ny))
                            simulation_field[nx][ny]+=1
                            key=1
                            break
                        elif simulation_field[nx][ny]>1:
                            key=1
                            break
                if key:break
        for x,y in set(enemy):
            simulation_field[x][y]=0
        simulation_field[H-1]=[0]*W
        for i in range(H-2,-1,-1):
            for j in range(W):
                if simulation_field[i][j]:
                    simulation_field[i][j]=0
                    simulation_field[i+1][j]=1
    answer=max(answer,kill_point_of_this_place)
print(answer)