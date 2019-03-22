import sys
sys.stdin = open('04344번 평균은 넘겠지\input.txt','r')

for i in range(int(input())):
    l=list(map(int,input().split()))
    c=l[0]
    l=l[1:]
    a=sum(l)/c
    print("%.3f%%" % (sum([1 for t in l if t>a])/c*100))