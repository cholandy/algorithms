import sys; input = lambda: sys.stdin.readline().rstrip()

cache = set()
def dfs2(idx, cw, wts) :
    if (idx, cw) in cache :
        return
    cache.add((idx, cw))
    if idx < len(wts) :
        dfs2(idx+1, cw+wts[idx], wts)
        dfs2(idx+1, abs(cw-wts[idx]), wts)
        dfs2(idx+1, cw, wts)

n = int(input())
wts = list(map(int,input().split()))
m = int(input())
balls = list(map(int,input().split()))
dfs2(0, 0, wts)
print(' '.join('Y' if (n, b) in cache else 'N' for b in balls))