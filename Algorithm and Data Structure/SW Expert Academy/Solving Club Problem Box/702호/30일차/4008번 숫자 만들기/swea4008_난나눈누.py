import sys;sys.stdin=open('input2.txt','r')
from itertools import combinations as pm

operator={
    0:'+',
    1:'-',
    2:'*',
    3:'/'
}

for tc in range(int(input())):
    N=int(input())
    aa=list(map(int,input().split()))
    tools=[]
    for i in range(len(aa)):
        for j in range(aa[i]):
            tools.append(operator[i])
   
    numbers=list(map(int,input().split()))
    MIN,MAX=float('inf'),-99999999
    

    print("#{} {}".format(tc+1,0))
