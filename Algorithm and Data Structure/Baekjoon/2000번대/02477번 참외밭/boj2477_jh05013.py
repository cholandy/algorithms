def polyarea(p):
    p.append(p[0])
    A = sum(p[i][0]*p[i+1][1]-p[i+1][0]*p[i][1] for i in range(len(p)-1))//2
    p.pop()
    return abs(A)

density = int(input())
p = [(0,0)]
x = 0
y = 0
for i in range(6):
    di, d = map(int,input().split())
    if di == 1: x+= d
    elif di == 2: x-= d
    elif di == 3: y-= d
    else: y+= d
    p.append((x,y))
print(polyarea(p) * density)