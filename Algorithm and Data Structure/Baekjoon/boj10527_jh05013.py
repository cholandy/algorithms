from sys import stdin
input = stdin.readline
dom = {}
kat = {}
n = int(input())
for i in range(n):
    s = input()
    if s in dom:
        dom[s]+= 1
    else:
        kat[s] = 0
        dom[s] = 1
for i in range(n):
    s = input()
    if s not in dom:
        dom[s] = 0
    if s in kat:
        kat[s]+= 1
    else:
        kat[s] = 1
print(sum(min(dom[s], kat[s]) for s in dom))