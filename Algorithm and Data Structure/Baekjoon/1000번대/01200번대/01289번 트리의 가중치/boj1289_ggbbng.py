P = 1000000007
DOWN = 0
UP = 1

N = int(input())
edge = {}
for i in range(N-1):
    v, v2, e = list(map(int, input().split()))
    if v not in edge:
        edge[v] = {}
    edge[v][v2] = e
    if v2 not in edge:
        edge[v2] = {}
    edge[v2][v] = e

stack = [(DOWN, 1)]
visited = {1:0}
tree = {}
weight = [(0, 0) for i in range(N+1)]

while len(stack) > 0:
    direction, v = stack.pop()
    if direction == DOWN:
        stack.append((UP, v))
        for v2 in edge[v]:
            if v2 not in visited:
                stack.append((DOWN, v2))
                visited[v2] = 0
                if v not in tree:
                    tree[v] = []
                tree[v].append(v2)
    else:
        if v not in tree:   # v is left node
            continue
        x = 0
        y = 0
        for i in range (len(tree[v])):
            v1 = tree[v][i]
            x1, y1 = weight[v1]
            y += x1 + y1 + edge[v][v1]*x*(1+x1)
            x += edge[v][v1]*(1 + x1)
        weight[v] = (x%P, y%P)

x, y = weight[v]
print((x+y)%P)
