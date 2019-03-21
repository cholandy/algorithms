from sys import stdin, stdout
input = stdin.readline
n = int(input())
size = 1
while size < n:
    size<<= 1
segtree = [(1000000001,99999)]*(size*2) # [1] is top node, array starts from 0

def segmin(L, R, node, NL, NR):
    # evaluate from L to R using #node whose segment is NL to NR
    if R < NL or L > NR:
        return (1000000001,99999)
    if L <= NL and NR <= R:
        return segtree[node]
    mid = (NL+NR)//2
    return min(segmin(L, R, node*2, NL, mid), segmin(L, R, node*2+1, mid+1, NR))

def update(i, val):
    # update index i to val
    i+= size
    segtree[i] = (val, i-size+1)
    while i > 1:
        i//= 2
        segtree[i] = min(segtree[i*2], segtree[i*2+1])

i = 0
for d in map(int,input().split()):
    update(i, d)
    i+= 1
m = int(input())
for i in range(m):
    a, b, c = map(int,input().split())
    if a == 1:
        update(b-1, c)
    else:
        stdout.write(str(segmin(b-1, c-1, 1, 0, size-1)[1])+'\n')