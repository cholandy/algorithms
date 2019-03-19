from sys import stdin
input = stdin.readline
n = int(input())
inter = []
for i in range(1, n+1):
    s, t = map(int,input().split())
    if s == t:
        inter.append((s,0))
    else:
        inter.append((s,1))
        inter.append((t,-1))
inter.sort()

maxroom = 0
curroom = 0
for t, ttype in inter:
    if ttype == 0:
        maxroom = max(maxroom, curroom+1)
    else:
        curroom+= ttype
        maxroom = max(maxroom, curroom)
print(maxroom)