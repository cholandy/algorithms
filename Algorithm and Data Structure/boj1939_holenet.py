import sys
sys.setrecursionlimit(100000000)
def input(): s = sys.stdin.readline(); return s[:-1] if s[-1]=='\n' else s
def iin(): return int(input())
def impin(): return map(int, input().split())
def irrin(): return [int(x) for x in input().split()]
def imrin(n): return [int(input()) for _ in range(n)]


def dijkstra(err, s):
    import heapq
    drr = [0]*len(err)
    vrr = [False]*len(err)
    pqueue = [(-1000000000000, s)]
    while True:
        while pqueue:
            d, x = heapq.heappop(pqueue)
            if not vrr[x]:
                break
        else:
            break
        drr[x] = d
        vrr[x] = True
        for y, dd in err[x]:
            if not vrr[y]:
                heapq.heappush(pqueue, (max(d, dd), y))
    return drr


n, m = impin()
err = [[] for _ in range(n)]
for _ in range(m):
    a, b, c = impin()
    err[a-1].append((b-1, -c))
    err[b-1].append((a-1, -c))
x, y = impin()
x -= 1
y -= 1
print(-dijkstra(err, x)[y])
