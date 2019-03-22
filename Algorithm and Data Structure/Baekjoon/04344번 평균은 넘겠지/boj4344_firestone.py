import sys
sys.stdin = open('04344번 평균은 넘겠지\input.txt','r')

for tc in range(int(input())):
    sc=list(map(int,input().split()))
    a=num=0
    for i in range(1,len(sc)):
        a+=sc[i]
    a/=sc[0]
    for i in range(1,len(sc)):
        if sc[i]>a:
            num+=1
    result = round(float(num/sc[0]*100),3)
    print("%0.3f" % result,end='');print('%')
    