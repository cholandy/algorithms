def cw(n, x, y):
    return y, n-1-x

def ccw(n, x, y):
    for i in range(3): x, y = cw(n, x, y)
    return x, y

def walk(n, m):
    if n == 2:
        if m == 1: return 0,0
        if m == 2: return 0,1
        if m == 3: return 1,1
        return 1,0
    half = n//2
    block = half**2
    if block >= m:
        x, y = walk(half, block-m+1)
        return cw(half, x, y)
    if block*2 >= m:
        x, y = walk(half, m-block)
        return x, y+half
    if block*3 >= m:
        x, y = walk(half, m-block*2)
        return x+half, y+half
    x, y = walk(half, block*4-m+1)
    x, y = ccw(half, x, y)
    return x+half, y

n, m = map(int,input().split())
x, y = walk(n, m)
print(x+1, y+1)