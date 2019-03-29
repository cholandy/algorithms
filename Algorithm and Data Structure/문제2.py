import sys;sys.stdin=open('C:\\Users\\student\\Desktop\\asdf\\Algorithm and Data Structure\\input2.txt','r')
from itertools import combinations as cb
input=__import__('sys').stdin.readline

def calc(x,y1,y2):
    global pan,N,M
    ret=[0,0,0,0,0,0]
    for i in range(x):
        for j in range(y1):
            ret[0]+=pan[i][j]
    for i in range(x):
        for j in range(y1,y2):
            ret[1]+=pan[i][j]
    for i in range(x):
        for j in range(y2,M):
            ret[2]+=pan[i][j]
    for i in range(x,N):
        for j in range(y1):
            ret[3]+=pan[i][j]
    for i in range(x,N):
        for j in range(y1,y2):
            ret[4]+=pan[i][j]
    for i in range(x,N):
        for j in range(y2,M):
            ret[5]+=pan[i][j]
    return ret

for tc in range(int(input())):
    N,M=map(int,input().split()) # N=행의 크기, M=열의 크기
    pan=[list(map(int,input().split())) for _ in range(N)]
    dp=[[0*N] for _ in range(int(M*(M-1)/2))]
    MAX=-99999
    for q in cb(range(1,N),1):
        for w,e in cb(range(1,M),2):
            a=q[0]
            b,c=w,e
            plot_sum=calc(a,b,c)
            for d,f,e in cb(plot_sum,3):
                tot=abs(d-f)+abs(f-e)+abs(e-d)
                if tot>MAX:
                    MAX=tot
         
    print(f'#{tc+1} {MAX}')