import sys
sys.stdin = open("C:\\Users\\student\\PycharmProjects\\algorithmproblems\\Soft Ware Expert Academy\\input.txt", "r")

def check(x, y):
    if not 0<=x<N : return False
    if not 0<=y<N : return False
    if maze[x][y] == 1  : return False
    return True


def DFS(x, y):
    stack = [0] * (N*N)
    top = -1
    # 만약에 탑이 인덱스의 마지막에 넣는다는 상황이라고 하자.
    # 탑을 +=1 해준다음 마지막 인덱스를 가리키고 채워 넣음
    # 문제는 탑으로 0으로 시작하는 것을
    # 스택에 미리 올린다음에
    top += 1
    stack[top] = x, y

    while top != -1:
        x, y = stack[top]
        top -= 1

        if maze[x][y] == 3 :
            return 1
        if maze[x][y] != 1 :
            maze[x][y] = 1
            for i in range(4):
                newX = x + dx[i]
                newY = y + dy[i]
                if check(newX, newY) :
                    top += 1
                    stack[top] = newX, newY
    return 0


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    maze = [[int(x) for x in input()] for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if maze[i][j] == 2 :
                X = i
                Y = j

    print('#%d'%tc, DFS(X, Y))


#
#
# import sys
# sys.stdin = open("input.txt", "r")
#
# def DFSr(x, y):
#     global found
#
#     if not 0 <= x < N or not 0 <= y < N or found or maze[x][y] == 1 :
#         return
#     if maze[x][y] == 3 :
#         found = 1
#         return
#
#     maze[x][y] = 1
#     DFSr(x, y+1)
#     DFSr(x, y-1)
#     DFSr(x+1, y)
#     DFSr(x-1, y)
#
#
# T = int(input())
# for tc in range(1, T + 1):
#     N = int(input())
#     maze = [[int(x) for x in input()] for _ in range(N)]
#
#     for i in range(N):
#         for j in range(N):
#             if maze[i][j] == 2 :
#                 X = i
#                 Y = j
#
#     found = 0
#     DFSr(X, Y)
#     print('#%d'%tc, found)