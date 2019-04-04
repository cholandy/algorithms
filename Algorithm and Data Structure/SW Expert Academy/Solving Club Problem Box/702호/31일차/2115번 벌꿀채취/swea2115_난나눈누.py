import sys;sys.stdin=open('input2.txt','r')
from itertools import combinations as cb

for t in range(int(input())):
    n,m,c=map(int,input().split())
    mat=[list(map(int,input().split())) for i in range(n)]
    honey=[[0 for _ in range(n)] for _ in range(n)]
    ansz=0 
    ans=0
    for i in range(n):
        for j in range(n):
            if j+m>n:continue               
            aemp=mat[i][j:j+m]
            mmax=0
            for v in range(1,m+1):
                for w in cb(aemp,v):
                    if sum(w)>c:continue
                    profit=0
                    for k in range(len(w)):
                        profit+=w[k]**2
                        if profit>mmax:
                            mmax=profit
            honey[i][j]=mmax
    for i in range(n):
        for j in range(n):
            if honey[i][j]:
                for k in range(n):
                    for l in range(n):
                        if honey[k][l]:
                            if i!=k or l-j>=m:
                                if honey[i][j]+honey[k][l]>ansz:
                                    ansz=honey[i][j]+honey[k][l]
                if ansz>ans:
                    ans=ansz
    print("#{} {}".format(t+1, ans))

