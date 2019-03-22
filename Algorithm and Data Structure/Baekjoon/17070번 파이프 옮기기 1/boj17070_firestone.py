import sys
sys.stdin = open('input.txt.','r')

n = int(input()) # n by n
board=[list(map(int,input().split())) for _ in range(n)] # input data
ret = [[[0,0,0] for _ in range(n)] for _ in range(n)] #dp용
# 모든 원소를 [왼쪽에서 온 경우의 수, 위에서 온 경우의 수, 대각선으로 온 경우의 수]으로 초기화

ret[0][1][0] = 1 #(1,2)가 시작포인트. 왼쪽에서 온 경우기 때문에 '첫 번째 요소 = 1'로 만들어줌. 
for i in range(n): # 모든 행을 순회
    for j in range(1, n): # 1열을 제외하고 순회
        if i==0 and j==1:continue # (1,2)는 시작포인트이므로 제외
        if board[i][j]==0: #(i+1, j+1)이 0이라면 파이프를 옮길 수 있음. 
            ret[i][j][0] = ret[i][j-1][0] + ret[i][j-1][2] #=> 왼쪽에서 오는 경우
            # (i+1, j+1)의 첫 번째 요소로는 바로 왼쪽칸의 1번째 요소 + 3번째 요소 
            ret[i][j][1] = ret[i-1][j][1] + ret[i-1][j][2] #=> 위에서 오는 경우
            # (i+1, j+1)의 두 번째 요소로는 바로 윗 칸의 2번째 요소 + 3번째 요소
            if board[i-1][j]==0 and board[i][j-1]==0: #=> 대각선에서 오는 경우
                # 만약 현재 칸의 바로 윗 칸과 오른쪽 칸이 0이라면
                ret[i][j][2] = ret[i-1][j-1][0] + ret[i-1][j-1][1] + ret[i-1][j-1][2]
                # 현재 칸의 3번째 요소 = 왼쪽 윗칸의 (1번째 요소 + 2번째 요소 + 3번째 요소)
print(sum(ret[n-1][n-1])) # (n,n) 칸의 요소를 다 더한 값

[print(ret[i]) for i in range(len(ret))]

# 만약 시작 포인트가 3가지라면? 
# 가로로 파이프가 놓여져 있는 경우 --> 이 문제의 상황
# 세로로 파이프가 놓여져 있는 경우 
# 대각선으로 파이프가 놓여져 있는 경우
# for i in range(13):
#     [print(0,end=' ') for _ in range(13)]
#     print()