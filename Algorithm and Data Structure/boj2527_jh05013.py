MIS = lambda: map(int,input().split())

def classify(x1, y1, x2, y2, x3, y3, x4, y4):
    minx = max(x1, x3)
    maxx = min(x2, x4)
    miny = max(y1, y3)
    maxy = min(y2, y4)
    if minx < maxx and miny < maxy: return 'a'
    if minx > maxx or miny > maxy: return 'd'
    if (x1,y1) == (x4,y4) or (x2,y2) == (x3,y3) or\
       (x2,y1) == (x3,y4) or (x1,y2) == (x4,y3): return 'c'
    return 'b'

for i in range(4):
    x1, y1, x2, y2, x3, y3, x4, y4 = MIS()
    print(classify(x1,y1,x2,y2,x3,y3,x4,y4))