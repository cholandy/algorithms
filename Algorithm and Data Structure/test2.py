def DFSr(v):
    print(v,end=' ')
    visited[v] = True

    for i in range(1, 8):
        if G[v][i] and not visited[i]:
            DFSr(i)


edges = [1, 2, 1, 3, 2, 4, 2, 5, 4, 6, 5, 6, 6, 7, 3, 7]
visited = [0] * 8
G = [[0] * 8 for _ in range(8)]

for i in range(0, len(edges), 2):
    G[edges[i]][edges[i+1]] = 1
    G[edges[i+1]][edges[i]] = 1

DFSr(1)
# [print(*i) for i in G]