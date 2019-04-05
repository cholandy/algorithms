# import sys;sys.stdin=open('input1.txt','r')
from itertools import combinations as cb, combinations_with_replacement as cr
import random
answers=[]
for t in range(10):
    film=[[random.randrange(0,2) for i in range(20)] for j in range(13)]
    D,W=13,20
    K=random.randint(1,13)
    ans = float('INF')
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
    if check(film) or K==1:ans=0;answers.append(ans);print(D,W,K);[print(*i) for i in film];continue
    pattern=[0]*W,[1]*W
    for n in range(D,0,-1):
        if n>=ans:break
        temp=film[:]
        cblist=cb(range(D), n)
        for idxlist in cblist:
            tempo=[0]*(1<<len(idxlist)-1)
            for c in range(1<<len(idxlist)):
                for d in range(c):
                    if c&(1<<d):
                        tempo[d]=1
                for i in range(len(idxlist)):
                    temp[idxlist[i]]=pattern[tempo[i]]
                if check(temp):ans=min(ans, n)
            temp=film[:]
    answers.append(ans)
    print(D,W,K)
    [print(*i) for i in film]
for i in range(10):
    print("#{} {}".format(i+1,answers[i]))
#1 9
#2 0
#3 7
#4 9
#5 13
#6 12
#7 12
#8 7
#9 7
#10 6