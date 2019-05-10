import sys;sys.stdin=open('input.txt','r')


dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]
arr = [] #
for tc in range(int(input())):
    # N => 원소의 갯수
    N = int(input()) 
    for _ in range(N):
        # 차례대로 x좌표, y좌표, 방향, 에너지 
        x, y, d, k = map(int, input().split())
        arr.append((2*x, 2*y, d, k))
    total_energy = 0
    while N: # 원소가 한 개라도 남아 있을 때까지 계속 돈다.
        temp = []
        # 원소가 만나는 지점을 저장할 배열
        crash = set()
        cset = set()
        for x,y,d,k in arr:
            # x,y 좌표를 업데이트 해준다. 
            x += dx[d]
            y += dy[d]
            # 업데이트한 좌표를 임시 배열에 저장한다.
            temp.append((x, y, d, k))
            # c는 cset의 원소 갯수
            c = len(cset)
            cset.add((x,y))
            # (x,y)를 더했는데도 원소 갯수가 변하지 않으면
            if c == len(cset):
                # 해당 좌표는 부딪히는 좌표를 의미
                crash.add((x,y))
        arr.clear()
        for x,y,d,k in temp:
            # 업데이트된 좌표값이 부딪힌 좌표값 중 하나라면
            if (x,y) in crash:
                # 에너지를 더해주고
                total_energy += k
                # 원소 하나 줄여준다.
                N -= 1
            # x,y 중 하나라도 좌표값을 벗어나면 원소 제거
            elif max(x, y) > 2000 or min(x, y) < -2000:
                N -=1
            # 위에 둘 중 하나라도 해당하지 않으면
            else:
                # arr에 다시 저장한다.
                arr.append((x,y,d,k)) 
    print(f"#{tc+1}", total_energy)