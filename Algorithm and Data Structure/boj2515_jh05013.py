from sys import stdin
input = stdin.readline

n, s = map(int,input().split())
paint = [tuple(map(int,input().split())) for i in range(n)] # h, c
paint.sort()

opt = [0] # opt when i-th is picked last
allow = [0] # second last pick available for picking i-th last
premax = [0] # opt with first i pictures
for i in range(n):
    k = allow[-1]
    while k != n and paint[k][0]+s <= paint[i][0]: k+= 1
    allow.append(k)
    opt.append(paint[i][1] + premax[allow[-1]])
    premax.append(max(premax[-1], opt[-1]))
print(premax[-1])