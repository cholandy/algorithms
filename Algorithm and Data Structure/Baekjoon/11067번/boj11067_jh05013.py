input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())

for TEST in range(int(input())):
    n = int(input())
    cx = {}
    for i in range(n):
        x, y = MIS()
        cx.setdefault(x, []).append(y)
    for x in cx: cx[x].sort()
    cafe = []
    last = 0
    for x in sorted(cx.keys()):
        col = cx[x]
        if col[0] != last: col.reverse()
        for y in col: cafe.append((x,y))
        last = col[-1]
    Q, *query = MIS()
    for q in query: print(*cafe[q-1])