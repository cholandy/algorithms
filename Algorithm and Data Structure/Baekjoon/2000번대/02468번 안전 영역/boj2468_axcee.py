import sys
input = lambda: sys.stdin.readline().rstrip()

def push_next(lenrow, lencol, r, c, chk_visited, do) :
    if 0 < r and chk_visited(r-1, c) :
        do(r-1, c)
    if r < lenrow-1 and chk_visited(r+1, c) :
        do(r+1, c)
    if 0 < c and chk_visited(r, c-1) :
        do(r, c-1)
    if c < lencol-1 and chk_visited(r, c+1) :
        do(r, c+1)
        
def count_unsinked(n, mat, height) :
    cnt = 0
    visited = [[mat[r][c] <= height for c in range(n)] for r in range(n)]
    for r in range(n) :
        for c in range(n) :
            if visited[r][c] :
                continue
            st = [(r,c)]
            while len(st) :
                x,y = st.pop()
                if visited[x][y] :
                    continue
                visited[x][y] = True
                push_next(n, n, x, y,
                          lambda r,c: not visited[r][c],
                          lambda r,c: st.append((r,c)))
            cnt += 1
    return cnt

def solve(n, mat) :
    ht = [x for row in mat for x in row] + [0]
    ht = list(set(ht))
    return max(count_unsinked(n, mat, h) for h in ht)

n = int(input())
mat = [[int(x) for x in input().split()] for i in range(n)]
print(solve(n, mat))