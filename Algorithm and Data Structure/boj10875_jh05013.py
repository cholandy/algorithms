INF = float('inf')
def collide(line1, line2):
    x1, y1, x2, y2 = line1
    x3, y3, x4, y4 = line2
    if (x4,y4) == (x1,y1): return INF # last move
    h1 = (y1 == y2) # line 1 is horizontal?
    h2 = (y3 == y4) # line 2 is horizontal?
    if not h1 and not h2: # Vertical vertical: rotate
        x1, y1, x2, y2, x3, y3, x4, y4 = y1, x1, y2, x2, y3, x3, y4, x4
        h1, h2 = True, True
    if h1 and h2: # Horizontal horizontal
        if y1 != y3: return INF
        if x1 > x2: x1, x2, x3, x4 = -x1, -x2, -x3, -x4
        if x2 < min(x3, x4) or x1 > max(x3, x4): return INF
        return min(x3, x4) - x1
    if not h1 and h2: # Vertical horizontal: rotate
        x1, y1, x2, y2, x3, y3, x4, y4 = y1, x1, y2, x2, y3, x3, y4, x4
    # Horizontal vertical
    if x1 > x2: x1, x2, x3, x4 = -x1, -x2, -x3, -x4
    if not min(y3, y4) <= y1 <= max(y3, y4): return INF
    if max(x1, x2) < x3 or min(x1, x2) > x3: return INF
    return x3 - min(x1, x2)

direc = [(1,0), (0,1), (-1,0), (0,-1)] # RULD
L = int(input())+1
n = int(input())
wall = [(L,-L,L,L), (L,L,-L,L), (-L,L,-L,-L), (-L,-L,L,-L)]

x = 0
y = 0
t = 0
di = 0
for i in range(n+1):
    if i == n: ti, turn = 2*L, "L"
    else: ti, turn = input().split(); ti = int(ti)
    nx, ny = x+direc[di][0]*ti, y+direc[di][1]*ti # new position
    sseg = (x, y, nx, ny) # segment of snake
    tc = min(collide(sseg, swall) for swall in wall) # minimum collision time
    if tc != INF:
        print(t + tc)
        exit()
    if turn == "L": di = (di+1)%4
    else: di = (di-1)%4
    x, y = nx, ny
    t+= ti
    wall.append(sseg)
