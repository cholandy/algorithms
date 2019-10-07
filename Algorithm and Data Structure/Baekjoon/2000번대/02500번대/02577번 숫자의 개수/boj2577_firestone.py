import sys;sys.stdin=open('input1.txt','r')
input=__import__('sys').stdin.readlines
a,b,c=map(int, input())
result=[0 for _ in range(10)]
m=a*b*c
while len(str(m))>1:
    result[m%10]+=1
    m//=10
    if m<10:result[m]+=1;break
[print(i) for i in result]