import sys; input = lambda: sys.stdin.readline().rstrip()

def solve(graph, fr, to) :
    v = [False for i in range(len(graph))]
    stack = [(fr, 0, 0)]
    while len(stack) :
        ni, tt, mx = stack.pop()
        if ni == to :
            return tt - mx
        v[ni] = True
        for chd, wt in graph[ni] :
            if v[chd] :
                continue
            stack.append((chd, tt+wt, max(mx, wt)))
    return -1

n, fr, to = map(int, input().split())
graph = [[] for i in range(n+1)]
for i in range(n-1) :
    x,y,w = map(int, input().split())
    graph[x].append((y,w))
    graph[y].append((x,w))
print(solve(graph, fr, to))