from itertools import combinations, permutations

piece = []
for i in range(5):
    row = input()
    for j in range(5):
        if row[j] == '*': piece.append((i,j))
n = len(piece)

def move(p, q): return abs(p[0]-q[0]) + abs(p[1]-q[1])
def cost(A, B): return sum(move(A[i], B[i]) for i in range(n))
def connected(C):
    stack = [0]
    vis = [True] + [False]*(n-1)
    while stack:
        p = stack.pop()
        for q in range(n):
            if vis[q] or move(C[p], C[q]) != 1: continue
            vis[q] = True; stack.append(q)
    return all(vis)

poss = 9999
slot = [(i,j) for i in range(5) for j in range(5)]
for C in combinations(slot, n):
    if not connected(C): continue
    val = min(cost(piece, P) for P in permutations(C, n))
    poss = min(poss, val)
print(poss)