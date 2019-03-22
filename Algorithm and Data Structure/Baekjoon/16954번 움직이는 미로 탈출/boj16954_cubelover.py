import sys
sys.stdin = open('C:Baekjoon\\16954번 움직이는 미로 탈출\\input.txt','r')

input = __import__('sys').stdin.readline
a = [input() for _ in range(8)] # 체스판 
d = [[False] * 8 for _ in range(8)] # dp용 배열
d[7][0] = True
for i in range(8): # 0초부터 7초까지 살펴봄

    #-- 벽이 내려온 것을 다시 맞춰주는 작업-- --#
    # 0초일 때는 사실상 필요 없음
    for j in range(8-i): 
        for k in range(8): #(j+1,k+1) 포인트
            if a[j][k] == '#':
                d[i + j][k] = False
    #-- -- -- -- -- -- -- -- -- -- -- -- -- --#           
    td = [[False] * 8 for _ in range(8)]
    #-- -- -- -- --케릭터가 갈 수 있는 곳을 True로 만들기-- -- -- --#
    for j in range(8):
        for k in range(8):
            for x in range(-1, 2): 
                for y in range(-1, 2): 
                    # 순서대로 - [5]가 현재 위치 
                    #  1 | 2 | 3
                    # --- --- ---
                    #  4 |[5]| 6 
                    # --- --- ---
                    #  7 | 8 | 9
                    
                    if 0<= j+x <8 and 0<= k+y <8 and d[j+x][k+y]:
                        td[j][k] = True
    #-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --#                       
    for j in range(8 - i):
        for k in range(8):
            if a[j][k] == '#':
                td[i+j][k] = False
    d = td
    print(f'{i} 초 후')
    [print(i) for i in td];print()

print(1 if sum(map(sum, d)) else 0)