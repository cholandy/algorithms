def cross(x, y):
    ax, bx = hull[x]; ay, by = hull[y]
    return (by-bx) / (ax-ay)

def insert(a, b):
    hull.append((a,b))
    while len(hull) > 2 and cross(-2,-3) > cross(-1,-2): hull.pop(-2)

n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
p = 0
dp = [0]
hull = [(b[0],0)]
for i in range(1, n):
    while p+1 < len(hull) and cross(p,p+1) <= a[i]: p+= 1
    dp.append(hull[p][0]*a[i] + hull[p][1])
    insert(b[i], dp[i])
print(dp[-1])