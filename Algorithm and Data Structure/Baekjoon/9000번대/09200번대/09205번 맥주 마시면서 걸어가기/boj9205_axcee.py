import sys; input = lambda: sys.stdin.readline().rstrip()

def distance(p, q) :
    return abs(p[0]-q[0]) + abs(p[1]-q[1])

def solve(cs, dst) :
    v = [False for i in range(len(cs))]
    st = [(0, cs[0])]
    while len(st) :
        ci, pos = st.pop()
        if v[ci] :
            continue
        v[ci] = True
        if distance(pos, dst) <= 1000 :
            return True
        for ni in range(len(cs)) :
            if not v[ni] and distance(cs[ni], pos) <= 1000 :
                st.append((ni, cs[ni]))
    return False

tc = int(input())
for t in range(tc) :
    n = int(input())
    cs = [tuple(map(int,input().split())) for i in range(n+1)]
    dst = tuple(map(int,input().split()))
    print('happy' if solve(cs, dst) else 'sad')
