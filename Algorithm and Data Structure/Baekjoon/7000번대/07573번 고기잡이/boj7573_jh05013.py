from sys import stdin
input = stdin.readline

def catch(x, y, w, h):
    res = 0
    for fx, fy in fish:
        if x<=fx<=x+w and y<=fy<=y+h: res+= 1
    return res

n, l, m = map(int,input().split())
X = set()
Y = set()
fish = []
for i in range(m):
    x, y = map(int,input().split())
    X.add(x)
    Y.add(y)
    fish.append((x,y))
X = sorted(X)
Y = sorted(Y)
opt = 0
for w in range(1, l//2):
    h = l//2-w
    for x in X:
        for y in Y:
            opt = max(opt, catch(x, y, w, h))
print(opt)