import sys;sys.stdin=open('input1.txt','r')
def update():
    global answer
    total_min_time=0
    for stair_index in range(2):
        now_stair=stair[stair_index]
        arrival_time=[0]*(maxn*2)
        current_stair=[0]*maxt
        for man_index in range(M):
            if match[man_index]==stair_index:
                    arrival_time[dist(man_index,stair_index)+1]+=1
        now_min_time=0
        for time in range(1,21):
            while arrival_time[time]>0:
                arrival_time[time]-=1
                remain_time=mat[now_stair[0]][now_stair[1]]
                for walk_time in range(time, maxt):
                    if current_stair[walk_time]<3:
                        current_stair[walk_time]+=1
                        remain_time-=1
                        if remain_time==0:
                            now_min_time=max(now_min_time,walk_time+1)
                            break
        total_min_time=max(total_min_time,now_min_time)
    answer=min(answer,total_min_time)
 
def dist(man_index,stair_index):
    dx=abs(man[man_index][0]-stair[stair_index][0])
    dy=abs(man[man_index][1]-stair[stair_index][1])
    return dx+dy
 
for tc in range(int(input())):
    N=int(input())
    mat=[]
    stair=[]
    man=[]   
    answer=float('inf')
    maxn=11
    maxt=143
     
    for row in range(N):
        temp=list(map(int,input().split()))
        for col in range(N):
            if temp[col]==1:
                man.append([row,col])
            if temp[col]>1:
                stair.append([row,col])
        mat.append(temp)
 
    M=len(man)
 
    match=[0]*M
     
    def dfs(man_index):
        if man_index==M:
            update()
            return
        for i in range(2):
            match[man_index]=i
            dfs(man_index+1)
 
    dfs(0)
    print("#{} {}".format(tc+1,answer))