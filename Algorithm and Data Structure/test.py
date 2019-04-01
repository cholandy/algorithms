import sys;sys.stdin=open('input1.txt','r')
from collections import deque
dx=[1,-1,10]

for tc in range(int(input())):
    n,m=map(int,input().split())
    visited=[0]*10000000
    cnt=0
    Q=deque((m,cnt))
    visited[m]=1
    while Q:
        a,b=Q.popleft()
        if a==n:
            print(b)
            break
        if 1<=a<=1000000:
            for i in range(4):
                if i==0:
                    if a%2==0:
                        new_a=a//2
                        if visited[new_a]==1:continue
                        Q.append((new_a,b+1))
                else:
                    new_a=a+dx[i-1]
                    if visited[new_a]==1:continue
                    Q.append((new_a,b+1))
    
        


    
    
    


    
    