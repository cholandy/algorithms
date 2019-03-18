def mkpr(n) :
    pr = [True for i in range(n+1)]
    pr[0] = pr[1] = False
    for i, p in enumerate(pr) :
        if p :
            for j in range(i*2, len(pr), i) :
                pr[j] = False
    return pr

pr = mkpr(1000000)
m, n = map(int, input().split())
for p in range(m, n+1) :
    if pr[p] : print(p)
