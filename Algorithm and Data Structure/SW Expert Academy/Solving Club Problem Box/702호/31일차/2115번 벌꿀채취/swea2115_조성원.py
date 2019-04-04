import sys;sys.stdin=open('input2.txt','r')

def price_calc(temp, col, num_sum, value):
    global C, N
    if num_sum > C:
        return 0
    if col == len(temp):
        return value
    return max(price_calc(temp, col + 1, num_sum + temp[col], value + temp[col]**2), price_calc(temp, col + 1, num_sum, value))
 
 
def bruteforce(num, value):
    global N, M, result
    if num == 2:
        result = max(value, result)
        return 0
    for i in range(N):
        for j in range(N - M + 1):
            if sum(visited[i][j:j + M]):
                continue
            temp = raw[i][j:j + M]
            max_temp = price_calc(temp, 0, 0, 0)
            visited[i][j:j + M] = [1] * M
            bruteforce(num + 1, value + max_temp)
            visited[i][j:j + M] = [0] * M
 
 
T = int(input())
for tc in range(1, T + 1):
    N, M, C = map(int, input().split())
    raw = [list(map(int, input().split())) for _ in range(N)]
    visited = [[0] * N for _ in range(N)]
    result = 0
    bruteforce(0, 0)
    print('#{} {}'.format(tc, result))