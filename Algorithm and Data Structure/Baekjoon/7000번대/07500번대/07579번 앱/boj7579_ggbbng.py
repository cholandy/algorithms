N, M = [int(x) for x in input().split()]
memory = [int(x) for x in input().split()]
cost = [int(x) for x in input().split()]
max_mem = [[0 for _ in range(100*N + 1)] for _ in range(N)]
max_mem[0][cost[0]] = memory[0]
result = [0 for _ in range(100*N + 1)]
for n in range(1, N):
    for c in range(100*N + 1):
        max_mem[n][c] = max_mem[n - 1][c]
        if cost[n] <= c:
            max_mem[n][c] = max(max_mem[n][c], max_mem[n - 1][c - cost[n]] + memory[n])
        result[c] = max(result[c], max_mem[n][c])

for c in range(100*N + 1):
    if result[c] >= M:
        print(c)
        break



