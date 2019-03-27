import sys

n = int(input())
s = list()

for i in range(n):
    s.append(list(map(int, sys.stdin.readline().split())))

c = [[[] for i in range(11)] for j in range(5)]

for i, x in enumerate(s):
    for j in range(5):
        c[j][x[j]].append(i)

MAX = -1
MAXi = -1

for i in range(n):
    num = []
    for j in range(5):
        num.extend(c[j][s[i][j]])
    l = len(set(num))
    if(l > MAX):
        MAXi = i
        MAX = l

print(MAXi+1)
