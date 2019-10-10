def chkcnt(l, n):
    b = 0
    c = 0
    for i in l:
        if i == 1:
            b += 1
        else:
            if b == n:
                c += 1
            b = 0
    if b == n:
        c += 1
    return c


for i in range(int(input())):
    cnt = 0
    a, b = list(map(int, input().split()))
    m = []
    k = []
    for t in range(a):
        k.append([])
    for j in range(a):
        m.append(list(map(int, input().split())))
        if m[j].count(1) >= b:
            cnt += chkcnt(m[j], b)
        for t in range(a):
            k[t].append(m[j][t])
    for j in k:
        if j.count(1) >= b:
            cnt += chkcnt(j, b)
    print(f'#{i+1} {cnt}')
