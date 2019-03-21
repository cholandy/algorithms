from operator import lt, gt

def parse_cmp(cmps) :
    return [lt if c=='<' else gt for c in cmps]

def mkent(n, rev) :
    if not rev : return list(range(n))
    else : return list(range(9, 9-n, -1))

def sort(ent, cmp) :
    for i in range(len(ent)) :
        while i > 0 and not cmp[i-1](ent[i-1], ent[i]) :
            ent[i-1], ent[i] = ent[i], ent[i-1]
            i -= 1

def solve(k, cmp) :
    cmp = parse_cmp(cmp)
    xent = mkent(k+1, True)
    sort(xent, cmp)
    nent = mkent(k+1, False)
    sort(nent, cmp)
    return (''.join(str(x) for x in xent),
            ''.join(str(x) for x in nent))

k = int(input())
c = input().split()
mx, mn = solve(k, c)
print(mx)
print(mn)
