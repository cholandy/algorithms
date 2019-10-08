import sys

N = int(input())
S = []

# S = tuple(구간의 끝, 처음 == False or 끝 == True, index)
for i in range(N):
    a, b = map(int, sys.stdin.readline().split())
    S.append((a, False, i + 1))
    S.append((b, True, i + 1))

# 구간의 끝들을 정렬하되, 처음이 끝보다 앞에온다.
S.sort()

# 최대 클리크에 포함되는 구간을 저장
arr = [False] * N

# 최대 클리크의 개수
max = 0

# 클리크의 개수
result = 0

# max구하기
for i in range(2 * N):
    if not S[i][1]:
        result += 1
    else:
        result -= 1
    if result > max:
        max = result

# max에 해당하는 클리크들 및 max 출력하기
result = 0
for i in range(2 * N):
    if not S[i][1]:
        result += 1
        arr[S[i][2] - 1] = True
    else:
        result -= 1
        arr[S[i][2] - 1] = False
    if result == max:
        print(result)
        for j in range(N):
            if arr[j]:
                print(j + 1, end=" ")
        break