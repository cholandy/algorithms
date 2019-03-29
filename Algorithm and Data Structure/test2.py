import sys;sys.stdin=open('input.txt','r')
input=__import__('sys').stdin.readline

T=int(input())
for tc in range(1,T+1):
    day,month,quarter,year=map(int,input().split())
    arr=list(map(int,input().split()))
    MIN=year

    def calc(n,cost):#첫 번째 인자는 월, 두 번째 인자는 비용
        global MIN
        #0월부터 11월까지 볼 것. 
        #base condition은 n이 12이상 되는 상황
        if n>11:
            MIN=min(MIN,cost)
            return
        if arr[n]==0:
            calc(n+1, cost)
        else:
            calc(n+1, cost+day*arr[n])
            calc(n+1, cost+month)
            calc(n+3, cost+quarter)
    calc(0,0)
    print(MIN)