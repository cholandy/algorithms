import sys, math
sys.stdin = open('Baekjoon\\01002번 터렛\input.txt','r')

for tc in range(int(input())):
    x1,y1,r1,x2,y2,r2=map(int,input().split())
    d=math.sqrt((x1-x2)**2+(y1-y2)**2)
    m,p=abs(r1-r2),r1+r2
    if d<m or d>p: print(0);continue
    if d==m or d==p: 
        if d==0 and m==0: print(-1);continue
        print(1);continue
    if m<d<p:print(2) 

