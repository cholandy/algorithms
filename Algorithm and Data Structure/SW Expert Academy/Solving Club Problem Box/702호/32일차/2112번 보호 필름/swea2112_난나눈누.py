import sys;sys.stdin=open('input1.txt','r')
from itertools import combinations as cb
from copy import deepcopy as dc
def check(arr):
    for j in range(W):
        for i in range(0,D-K+1):
            key=False
            temp=[]
            si=i
            for _ in range(K):
                temp.append(arr[si][j])
                si+=1
            if len(set(temp))==1:
                key=True
                break
        if key==False:
            return False
    return True

def recur(status,depth,b,match):
    global ans
    if len(b)>ans:return
    match[depth]=status
    if depth+1==len(b):
        temp=dc(film)
        for i in range(len(b)):
            for j in range(W):
                temp[b[i]][j]=match[i]
        if check(temp):
            ans=len(b)
            return 
        else:
            return 
    recur(0,depth+1,b,match)
    recur(1,depth+1,b,match)



for t in range(int(input())):
    ans=float('inf')
    D,W,K=map(int,input().split())
    film=[list(map(int,input().split())) for _ in range(D)]
    if check(film):
        print("#{} {}".format(t+1,0));continue
    
    for a in range(1,D+1):
        for b in cb(range(D), a):
            match=[0]*D
            recur(0,-1,b,match)
    print("#{} {}".format(t+1,ans))