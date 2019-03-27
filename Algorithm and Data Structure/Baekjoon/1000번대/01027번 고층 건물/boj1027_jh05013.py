def ccw(p1, p2, p3):
    # positive -> ccw; negative -> cw; 0 -> collinear
    return (p2[0]-p1[0])*(p3[1]-p1[1]) - (p2[1]-p1[1])*(p3[0]-p1[0])

def visibleR(p1, p2):
    for i in range(p1[0]+1, p2[0]):
        if ccw(p1, point[i], p2) <= 0: return False
    return True

def visibleL(p1, p2):
    for i in range(p2[0]+1, p1[0]):
        if ccw(p1, point[i], p2) >= 0: return False
    return True

n = int(input())
point = list(enumerate(map(int,input().split())))
vis = [0]*n
for i in range(n):
    for j in range(i): vis[i]+= visibleL(point[i], point[j])
    for j in range(i+1, n): vis[i]+= visibleR(point[i], point[j])
print(max(vis))