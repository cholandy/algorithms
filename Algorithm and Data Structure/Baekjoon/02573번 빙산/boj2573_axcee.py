import sys; input = lambda: sys.stdin.readline().rstrip()

def drange(n, m) :
    for r in range(n) :
        for c in range(m) :
            yield r, c

def reduce(n, m, iceberg) :
    task = []
    for r, c in drange(n, m) :
        if iceberg[r][c] == 0 :
            continue
        cnt = 0
        cnt += 0 < r and iceberg[r-1][c] == 0
        cnt += r < n-1 and iceberg[r+1][c] == 0
        cnt += 0 < c and iceberg[r][c-1] == 0
        cnt += c < m-1 and iceberg[r][c+1] == 0
        task.append((r, c, cnt))
    for r, c, cnt in task :
        iceberg[r][c] = max(iceberg[r][c]-cnt, 0)

def count_masses(n, m, iceberg) :
    def visit(ir, ic) :
        stack = [(ir, ic)]
        while len(stack) :
            r, c = stack.pop()
            if v[r][c] :
                continue
            v[r][c] = True
            if 0 < r and iceberg[r-1][c] != 0 and not v[r-1][c] :
                stack.append((r-1, c))
            if r < n-1 and iceberg[r+1][c] != 0 and not v[r+1][c] :
                stack.append((r+1, c))
            if 0 < c and iceberg[r][c-1] != 0 and not v[r][c-1] :
                stack.append((r, c-1))
            if c < m-1 and iceberg[r][c+1] != 0 and not v[r][c+1] :
                stack.append((r, c+1))
                
    v = [[False for c in range(m)] for r in range(n)]
    cnt = 0
    for r, c in drange(n, m) :
        if iceberg[r][c] != 0 and not v[r][c] :
            visit(r, c)
            cnt += 1
    return cnt

def solve(n, m, iceberg) :
    year = 0
    while True :
        cnt = count_masses(n, m, iceberg)
        if cnt >= 2 :
            break
        if cnt == 0 :
            return 0
        reduce(n, m, iceberg)
        year += 1
    return year

n, m = map(int, input().split())
ib = [list(map(int,input().split())) for i in range(n)]
print(solve(n,m,ib))