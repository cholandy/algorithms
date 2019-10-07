
# import sys; input = lambda: sys.stdin.readline().rstrip()

from math import inf

class Point :
    def __init__(self, x, y) :
        self.x = x
        self.y = y

def distance(p1, p2) :
    return (p1.x - p2.x)**2 + (p1.y - p2.y)**2

def dnc(pts, lo, hi) :
    if lo == hi :
        return inf
    mid = (lo + hi)//2
    left = dnc(pts, lo, mid)
    right = dnc(pts, mid+1, hi)
    d = min(left, right)
    buf = []
    
    i = mid
    while lo <= i and (pts[i].x - pts[mid].x)**2 < d :
        buf.append(pts[i])
        i -= 1
    i = mid+1
    while i <= hi and (pts[i].x - pts[mid].x)**2 < d :
        buf.append(pts[i])
        i += 1
    
    buf.sort(key = lambda p:p.y)
    for i in range(len(buf)) :
        for j in range(i+1, len(buf)) :
            td = distance(buf[i], buf[j])
            if td >= d :
                break
            else :
                d = td
    return d

def solve(pts) :
    pts.sort(key = lambda p : p.x)
    return dnc(pts, 0, len(pts)-1)

for i in range(int(input())):
    n = int(input())    
    pts = [Point(*tuple(map(int,input().split()))) for i in range(n)]
    print(f'#{i+1} {solve(pts)}')
