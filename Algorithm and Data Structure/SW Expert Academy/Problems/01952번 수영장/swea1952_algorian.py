T=int(input())
for tc in range(1,T+1):
    day,month,quarter,year=map(int,input().split())
    arr=list(map(int,input().split()))
    MIN=year

    def calc(n,cost):
        global MIN

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
    print(f'#{tc} {MIN}')