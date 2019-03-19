import sys; input = lambda: sys.stdin.readline().rstrip()

def nextpos(n, m) :
    s = n*m
    for i in range(s) :
        for j in range(i+1, s) :
            for k in range(j+1, s) :
                yield (*divmod(i,m), *divmod(j,m), *divmod(k,m))

def calc_safetyzone(zone) :
    return sum(sum(c==0 for c in r) for r in zone)

def drange(n, m) :
    for r in range(n) :
        for c in range(m) :
            yield r, c
            
def spread(n, m, zone) :
    for ri, ci in drange(n, m) :
        if zone[ri][ci] == 2 :
            zone[ri][ci] = 0
            st = [(ri,ci)]
            while len(st) :
                r, c = st.pop()
                if zone[r][c] != 0 :
                    continue
                zone[r][c] = 2
                if 0 < r and zone[r-1][c] == 0 :
                    st.append((r-1, c))
                if r < n-1 and zone[r+1][c] == 0 :
                    st.append((r+1, c))
                if 0 < c and zone[r][c-1] == 0 :
                    st.append((r, c-1))
                if c < m-1 and zone[r][c+1] == 0 :
                    st.append((r, c+1))

def copyzone(zone) :
    return [[z for z in r] for r in zone]

def solve(n, m, zone) :
    maxsz = 0
    for r1, c1, r2, c2, r3, c3 in nextpos(n, m) :
        if not (zone[r1][c1]==0 and zone[r2][c2]==0 and zone[r3][c3]==0) :
            continue
        zcopy = copyzone(zone)
        zcopy[r1][c1] = 1
        zcopy[r2][c2] = 1
        zcopy[r3][c3] = 1
        spread(n, m, zcopy)
        maxsz = max(maxsz, calc_safetyzone(zcopy))
    return maxsz


n, m = map(int,input().split())
z = [list(map(int,input().split())) for i in range(n)]
print(solve(n, m, z))
