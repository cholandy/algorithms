from collections import deque
import sys;sys.stdin=open('input.txt','r') 
T = int(input())
for test_case in range(1, T + 1):
 
    N, M, K = map(int, input().split())
    arr = []
 
    dxy = [[0, 1], [0, -1], [1, 0], [-1, 0]]
 
    for n in range(N):
        arr += [list(map(int, input().split()))]
 
    stem_cells = [[] for _ in range(11)]
 
    already_filled = [[False for _ in range(M + 2 * K + 2)] for _ in range(N + 2 * K + 2)]
 
    for i in range(N):
        for j in range(M):
            if arr[i][j] > 0:
                stem_cells[arr[i][j]] += [(i, j)]
 
    cells = deque()
    life_span = deque()
    activate_time = deque()
 
    for idx in range(10, 0, -1):
        if len(stem_cells[idx]) > 0:
            for location in stem_cells[idx]:
                already_filled[location[0]][location[1]] = True
                cells.append(location)
                life_span.append(idx)
                activate_time.append(idx)
 
    for k in range(K):
 
        original_cells = len(cells)
 
        for R in range(original_cells):
 
            C = cells.popleft()
            L = life_span.popleft()
            IA = activate_time.popleft()
 
            if IA > 0:
                cells.append((C[0], C[1]))
                life_span.append(L)
                activate_time.append(IA - 1)
 
            elif IA == 0:
                for delta in dxy:
                    if not already_filled[C[0] + delta[0]][C[1] + delta[1]]:
                        already_filled[C[0] + delta[0]][C[1] + delta[1]] = True
                        cells.append((C[0] + delta[0], C[1] + delta[1]))
                        life_span.append(L)
                        activate_time.append(L)
 
                if L - 1 > 0:
                    cells.append((C[0], C[1]))
                    life_span.append(L - 1)
                    activate_time.append(-1)
 
            elif IA < 0:
                if L - 1 > 0:
                    cells.append((C[0], C[1]))
                    life_span.append(L - 1)
                    activate_time.append(-1)
 
    print("#{} {}".format(test_case, len(cells)))