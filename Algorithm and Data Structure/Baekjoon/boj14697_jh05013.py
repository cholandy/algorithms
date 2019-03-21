a, b, c, n = map(int,input().split())
for i in range(n+3):
    nbc = n-a*i
    if nbc < 0: break
    for j in range(n+3):
        nc = nbc-b*j
        if nc < 0: break
        if nc%c == 0: print(1); exit()
print(0)