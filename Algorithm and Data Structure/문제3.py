import sys;sys.stdin=open('problem3_input.txt')
from itertools import permutations as pm
input=__import__('sys').stdin.readline

for tc in range(int(input())):
    N=int(input())
    snack=list(map(int,input().split()))
    robot=list(map(int,input().split()))
    MIN=float('INF')
    snacks=[]
    robots=[]
    for i in range(0,2*N,2):
        snacks.append([snack[i],snack[i+1]])
        robots.append([robot[i],robot[i+1]]) 
    for pmRobots in pm(robots,N):
        pmRobots=list(pmRobots) # [[2,2],[2,5],[5,0]]
        comp=0
        for i in range(N):
            a,b=pmRobots[i][0],pmRobots[i][1]
            c,d=snacks[i][0],snacks[i][1]
            comp+=abs(a-c)+abs(b-d)
            if comp>=MIN:break
            if i==N-1 and comp<MIN:MIN=comp

    print(f'#{tc+1} {MIN}')