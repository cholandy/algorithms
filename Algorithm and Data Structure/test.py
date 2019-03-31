import sys;sys.stdin=open('input1.txt','r')
input=__import__('sys').stdin.readline

for tc in range(int(input())):
    num=int(input())
    aa=[i for i in range(2,num+1)]
    for j in range(2,round(num**(1/2))+1):
        for i in aa:
            if i%j==0 and i!=j:
                aa.remove(i)
    cnt=0
    a=0
    for i in range(len(aa)):
        if aa[i]>=num//2:
            c=i
            break
    for i in range(0,c+1):
        for j in range(c,len(aa)):        
            if aa[i]+aa[j]==num:
                cnt+=1
    print(cnt)
    # print(aa)
    # for i in range()