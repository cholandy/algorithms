import sys;sys.stdin=open('input2.txt','r')
def drain_honey(row, col):
    global M, C, ans
    # 왼쪽은 누적 가격, 오른쪽은 여유 공간
    basket = [[] for _ in range(2**M)]
    basket[0] = [0, C]
    top = 1
    for x in range(M):
        honey = field[row][col+x]
        for y in range(top):
            if basket[y][1] >= honey:
                basket[top] = [basket[y][0] + honey**2, basket[y][1] - honey]
                top += 1
    return max(basket)[0]
 
 
 
testcase = int(input())
 
for tc in range(1, testcase + 1):
    N, M, C = map(int, input().split())
    field = [list(map(int, input().split())) for _ in range(N)]
    ans = 0
 
    # 각 좌표에 있다고 가정하에 최대 수익 미리 계산
    max_prices = [[0]*(N-M+1) for _ in range(N)]
    for r in range(N):
        for c in range(N-M+1):
            max_prices[r][c] = drain_honey(r, c)
 
    # 일꾼1 자리 잡기
    for r1 in range(N):
        for c1 in range(N-M+1):
            # 일꾼1 자리 잡으면 최대 수익 불러옴
            max_price1 = max_prices[r1][c1]
             
            # 일꾼2 자리 잡기
            for r2 in range(r1, N):
                if r2 == r1:
                    for c2 in range(c1+M, N-M+1):
                        # 일꾼2 자리 최대 수익 불러옴
                        max_price2 = max_prices[r2][c2]
 
                        # 최고 가격 갱신 시도
                        ans = max(ans, max_price1 + max_price2)
                else:
                    for c2 in range(N-M+1):
                        max_price2 = max_price2 = max_prices[r2][c2]
                        ans = max(ans, max_price1 + max_price2)
 
    print("#{} {}".format(tc, ans))