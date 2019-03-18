class Rect(object):
    def __init__(self, L, R, D, U):
        assert L < R and D < U
        self.L, self.R, self.D, self.U = L, R, D, U
    def contain(self, r):
        return self.L <= r.L and r.R <= self.R and self.D <= r.D and r.U <= self.U
    def area(self): return (self.R-self.L)*(self.U-self.D)

def solve(F):
    N = len(F) # number of input rectangles
    x = set(); y = set() # x/y-coordinates of input rectangles
    for i in range(N):
        x.add(F[i].L); x.add(F[i].R)
        y.add(F[i].D); y.add(F[i].U)
    x = list(x); y = list(y)
    x.sort(); y.sort()

    sum = 0
    for i in range(len(x)-1):
        for j in range(len(y)-1):
            for k in range(N):
                r = Rect(x[i],x[i+1],y[j],y[j+1])
                if F[k].contain(r):
                    sum += r.area()
                    break
    return sum

##################################################
def test():
    N = int(input())
    F = []
    for i in range(N):
        s = input().split()
        r = Rect(float(s[0]), float(s[0])+float(s[2]), float(s[1]), float(s[1])+float(s[3]))
        F.append(r)
    result = solve(F)
    if result - int(result) < 1E-3: print("%d" % result)
    else: print("%.2f" % result)
    
test()