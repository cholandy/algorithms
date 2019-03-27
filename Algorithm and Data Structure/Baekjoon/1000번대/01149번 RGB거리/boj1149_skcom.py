import sys

p = [0] * 3

for i in range(int(input())):
    x = list(map(int, sys.stdin.readline().split()))
    t0 = min(p[1]+x[0],p[2]+x[0])
    t1 = min(p[0]+x[1],p[2]+x[1])
    t2 = min(p[0]+x[2],p[1]+x[2])
    p[0] = t0
    p[1] = t1
    p[2] = t2
    
print(min(p))
