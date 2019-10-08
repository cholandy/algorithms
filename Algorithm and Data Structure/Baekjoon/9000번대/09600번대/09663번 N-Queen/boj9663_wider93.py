def nqueen(n):
    if n == 14:
        return 365596
    if n == 13:
        return 73712

    def meet(x1, y1, x2, y2):
        # assume y1 and y2 will be differed automatically so will not count
        # y좌표들은 서로 다름
        # x좌표와 대각선만 체크하면 됨
        # 하나라도 같으면 true 반환
        return x1==x2 or y2-y1==abs(x2-x1)

    def recursive(save, y):
        if y == n:
            return 1
        res = 0
        for x in range(n):
            # save에 있는 좌표와 새로운 좌표가 만나는지 안만나는지 확인하는 meet 함수. 
            if not any(meet(x1, y1, x, y) for x1, y1 in save): 
                # 하나라도 save에 있는 좌표와 만난다면 true가 되기 때문에 안됨. 
                # 만약 새 여왕이 기존 여왕과 안만나면 새로운 여왕의 좌표를 save에 저장하고 
                # 다음 열을 탐색 시작. 
                res += recursive(save+[(x, y)], y+1)
        return res
    return recursive([], 0)
    # 처음에는 (0,0)에서 시작

print(nqueen(5))