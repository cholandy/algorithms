import sys;sys.stdin=open('input1.txt','r')
from itertools import combinations as cb, product
from time import time

a=time()
def check(arr):
    for j in range(W):
        next,cnt=0,1
        for i in range(D-1):
            if D-i<K and cnt==1:break
            if arr[i][j]==arr[i+1][j]:cnt += 1
            else:cnt=1;continue
            if cnt==K:next=1;break
        if not next:return False
    return True
for t in range(int(input())):
    D,W,K = map(int,input().split())
    film=[list(map(int,input().split())) for _ in range(D)]
    ans = float('INF')
    if check(film) or K==1:ans=0;print("#{} {}".format(t+1,ans));continue
    pattern=[0]*W,[1]*W
    if K>=6:
        for n in range(K,0,-1):
            temp=film[:]
            cblist=cb(range(D), n)
            for idxlist in cblist:
                key=False
                for k in product([0,1], repeat=len(idxlist)):
                    for i in range(len(idxlist)):
                        temp[idxlist[i]]=pattern[k[i]]
                    if check(temp):ans=min(ans, n);key=True;break
                if key:break
                temp=film[:]
        print("#{} {}".format(t+1,ans))
    else: 
        for n in range(1,K+1):
            temp=film[:]
            cblist=cb(range(D), n)
            for idxlist in cblist:
                key=False
                for k in product([0,1], repeat=len(idxlist)):
                    for i in range(len(idxlist)):
                        temp[idxlist[i]]=pattern[k[i]]
                    if check(temp):ans=min(ans, n);key=True;break
                if key:break
                temp=film[:]
        print("#{} {}".format(t+1,ans))
b=time()
print(b-a)
#1 2
#2 7
#3 5
#4 7
#5 5
#6 3
#7 6
#8 8
#9 7
#10 4
#11 6
# 2.7895395755767822