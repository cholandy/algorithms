def ccw(a, b, c):
    # positive -> ccw; negative -> cw; 0 -> collinear
    res = (b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0])
    return 0 if res==0 else (1 if res>0 else -1)

def intersect(a, b, c, d):
    # check if two line segments a--b and c--d intersect
    def cc(a, b, c):
        return min(a[0],b[0]) <= c[0] <= max(a[0],b[0]) and\
               min(a[1],b[1]) <= c[1] <= max(a[1],b[1]) 
    if a == b: return a in (c,d)
    if c == d: return c in (a,b)
    s1 = ccw(a,b,c); s2 = ccw(a,b,d)
    if s1==0 and s2==0:
        return any(cc(i,j,k) for i,j,k in ((a,b,c), (a,b,d), (c,d,a), (c,d,b)))
    if s1 and s1==s2: return False
    s1 = ccw(c,d,a); s2 = ccw(c,d,b)
    if s1 and s1==s2: return False
    return True

__import__('sys').setrecursionlimit(123123)
class DisjointSet:
    def __init__(self, n):
        self.par = list(range(n+1))
        self.size = [1]*(n+1)

    def union(self, x, y): # yr becomes parent
        xr = self.find(x); yr = self.find(y)
        if xr == yr: return
        self.par[xr] = yr
        self.size[yr]+= self.size[xr]
        
    def find(self, x):
        if self.par[x] != x: self.par[x] = self.find(self.par[x])
        return self.par[x]

n = int(input())
lines = []
for i in range(n):
    x1, y1, x2, y2 = map(int,input().split())
    lines.append(((x1,y1),(x2,y2)))
DS = DisjointSet(n)
for i in range(n):
    for j in range(i+1, n):
        if intersect(*lines[i], *lines[j]): DS.union(i, j)
print(sum(DS.par[i]==i for i in range(n)))
print(max(DS.size))