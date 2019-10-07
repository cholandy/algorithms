from sys import stdin
input = stdin.readline

for TEST in range(int(input())):
    n, l, k = map(int,input().split())
    left = []
    right = []
    ant = []
    for i in range(n):
        p, ID = map(int,input().split())
        if ID < 0: left.append(p)
        else: right.append(l-p)
        ant.append(ID)
    for i in range(len(left)): left[i] = (left[i], ant[i])
    for i in range(len(right)): right[~i] = (right[~i], ant[~i])
    print(sorted(left+right)[k-1][1])