for T in range(int(input())):
    m, n, x, y = map(int,input().split())
    x-= 1; y-= 1
    year, j, i = y+1, y, y%m
    if i == x: print(year); continue
    initiali = i
    while 1:
        year+= n
        i = (i+n)%m
        if i == initiali: print(-1); break
        if i == x: print(year); break