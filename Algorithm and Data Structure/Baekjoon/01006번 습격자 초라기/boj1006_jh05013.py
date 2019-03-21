input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())
INF = float('inf') # inf=infinity. It could be positive or negative infinity. 

def linear(top, bot):
    dpful = [INF] * (n+1); dpful[0] = 0
    dptop = [INF] * (n+1)
    dpbot = [INF] * (n+1)
    for i in range(1, n+1):
        dptop[i] = dpful[i-1] + 1
        if top[i] + top[i-1] <= w: dptop[i] = min(dptop[i], dpbot[i-1]+1)
        dpbot[i] = dpful[i-1] + 1
        if bot[i] + bot[i-1] <= w: dpbot[i] = min(dpbot[i], dptop[i-1]+1)
        dpful[i] = min(dptop[i], dpbot[i]) + 1
        if top[i] + bot[i] <= w: dpful[i] = min(dpful[i], dpful[i-1]+1)
        if top[i] + top[i-1] <= w and bot[i] + bot[i-1] <= w:
            dpful[i] = min(dpful[i], dpful[i-2]+2)
    return dpful[-1]

for TEST in range(int(input())):
    n, w = MIS()
    top = [INF]+list(MIS())
    bot = [INF]+list(MIS())
    ans = linear(top, bot)
    if n == 1: print(ans); continue
    if top[1] + top[-1] <= w:
        top[1]+= w; top[-1]+= w
        ans = min(ans, linear(top, bot) - 1)
        top[1]-= w; top[-1]-= w
    if bot[1] + bot[-1] <= w:
        bot[1]+= w; bot[-1]+= w
        ans = min(ans, linear(top, bot) - 1)
        bot[1]-= w; bot[-1]-= w
    if top[1] + top[-1] <= w and bot[1] + bot[-1] <= w:
        top[1]+= w; top[-1]+= w
        bot[1]+= w; bot[-1]+= w
        ans = min(ans, linear(top, bot) - 2)
    print(ans)