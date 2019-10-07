from collections import deque
T = int(input())

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
for tc in range(T):
    M, N, K = map(int, input().split())
    arr = [[0]*M for _ in range(N)]
    for _ in range(K):
        x, y = map(int, input().split())
        arr[y][x] = 1
    Q = deque()
    ans = 0
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 1:
                x, y = i, j
                Q.append((x, y))
                while Q:
                    sx, sy = Q.pop()
                    for d in range(4):
                        nx, ny = sx+dx[d], sy+dy[d]
                        if 0 <= nx < N and 0 <= ny < M and arr[nx][ny]:
                            Q.append((nx, ny))
                            arr[nx][ny] = 0
                ans += 1
    print(ans)
