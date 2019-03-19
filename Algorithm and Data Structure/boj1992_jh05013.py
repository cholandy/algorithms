def scan(L,size,x0,y0):
    # Scan L[y0:+size][x0:+size]
    if size == 1:
        return L[y0][x0]
    half = size//2
    LU = scan(L,half,x0,y0)
    RU = scan(L,half,x0+half,y0)
    LL = scan(L,half,x0,y0+half)
    RL = scan(L,half,x0+half,y0+half)
    if len(LU)==1 and LU==RU==LL==RL:
        return LU
    return "(%s%s%s%s)"%(LU,RU,LL,RL)

size = int(input())
a = [input() for i in range(size)]
print(scan(a,size,0,0))