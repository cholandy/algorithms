def LSS(seq):
    res = 0
    cur = 0
    for s in seq:
        cur+= s
        if cur < 0: cur = 0
        res = max(res, cur)
    return res

def SSS(seq):
    res = 0
    cur = 0
    for s in seq:
        cur+= s
        if cur > 0: cur = 0
        res = min(res, cur)
    return res

for TEST in range(int(input())):
    n, *c = map(int,input().split())
    print(max(LSS(c), sum(c)-SSS(c)))