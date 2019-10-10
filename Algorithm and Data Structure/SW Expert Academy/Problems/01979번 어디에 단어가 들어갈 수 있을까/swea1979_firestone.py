import sys
sys.stdin = open('input.txt', 'r')

for _ in range(int(input())):
    ans = 0
    N, K = map(int, input().split())
    # print(N, K)
    mat = []
    for i in range(N+2):
        if i in [0, N+1]:
            mat.append([0]*(N+2))
        else:
            a = [0] + list(map(int, input().split())) + [0]
            mat.append(a)
    rows = [[0]*N for _ in range(N)]
    cols = [[0]*N for _ in range(N)]
    [print(*i) for i in mat]
    print()
    for i in range(1, N+1):
        for j in range(1, N+1):
            if mat[i][j]:
                if j+K < N+2:
                    rows[i-1][j-1] = sum(mat[i][k] for k in range(j, j+K))
                if i+K < N+2:
                    cols[i-1][j-1] = sum(mat[k][j] for k in range(i, i+K))
    for i in range(N):
        for j in range(N):
            if rows[i][j] == K and mat[i+1][j] != 1 and mat[i+1][j+K+1] != 1:
                ans += 1
            if cols[i][j] == K and mat[i][j+1] != 1 and mat[i+K+1][j+1] != 1:
                ans += 1
    [print(*i) for i in rows]
    print()
    [print(*i) for i in cols]
    print()
    print("#{} {}".format(_+1, ans))
