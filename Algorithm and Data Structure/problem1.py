import sys, collections

sys.stdin = open("problem1_input.txt")

dx = [2, 3, 3, 2, -2, -3, -3, -2]
dy = [3, 2, -2, -3, -3, -2, 2, 3]
# index 는 0 ~ N-1
# BFS 백트래킹으로 풀기
testcase = int(input())

for tc in range(1, testcase + 1):
    N = int(input())
    x, y, tx, ty = map(int, input().split())
    min_cnt = 0xfffff
    # queue = [[x, y, 0]]
    new_queue = collections.deque()
    new_queue.append([x, y, 0])
    while new_queue:
        # s = queue.pop(0)
        s = new_queue.popleft()
        sx, sy, cnt = s[0], s[1], s[2]
        if sx == tx and sy == ty:
            if cnt < min_cnt:
                min_cnt = cnt
        if cnt < min_cnt:
            for d in range(8):
                if sx + dx[d] >= 0 and sx + dx[d] < N and sy + dy[d] >= 0 and sy + dy[d] < N:
                    # queue.append([sx + dx[d], sy + dy[d], cnt + 1])
                    z = [sx + dx[d], sy + dy[d], cnt + 1]
                    new_queue.append(z)
    print("#{} {}".format(tc, min_cnt))
