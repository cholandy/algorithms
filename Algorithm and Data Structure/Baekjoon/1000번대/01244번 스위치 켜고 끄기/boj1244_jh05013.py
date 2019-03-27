def toggle(i):
    switch[i] = 1-switch[i]

n = int(input())
switch = list(map(int,input().split()))
st = int(input())
for i in range(st):
    gen, k = map(int,input().split())
    if gen == 1:
        for p in range(k-1, n, k): toggle(p)
    else:
        toggle(k-1)
        l, r = k-2, k
        while 0<=l and r<n and switch[l] == switch[r]:
            toggle(l); l-= 1
            toggle(r); r+= 1
for i in range(0, n, 20):
    print(*switch[i:i+20])