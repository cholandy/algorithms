def dfs():
    s = []
    direct = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    dp = [[0] * m for _ in range(n)]


    res = 0
    while True:
        cnt1 = 0
        for i in range(n):
            for j in range(m):
                if arr[i][j] > 0:
                    s.append([i, j])
                    cnt1 += 1

        if not s:
            break

        visit = [[0] * m for _ in range(n)]
        s2 = [s[-1]]
        visit[s2[0][0]][s2[0][1]] = 1
        cnt2 = 0
        while s2:
            y, x = s2.pop()
            cnt2 += 1
            for dy, dx in direct:
                cy, cx = y + dy, x + dx

                if not visit[cy][cx] and arr[cy][cx] > 0:
                    visit[cy][cx] = 1
                    s2.append([cy, cx])

        if cnt1 != cnt2:
            print(res)
            exit(0)

        while s:
            y, x = s.pop()

            for dy, dx in direct:
                cy, cx = y + dy, x + dx

                if arr[cy][cx] <= 0:
                    dp[y][x] += 1

        for i in range(n):
            for j in range(m):
                if dp[i][j]:
                    arr[i][j] -= dp[i][j]
                    dp[i][j] = 0

        res += 1

    print(0)


n, m = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

dfs()