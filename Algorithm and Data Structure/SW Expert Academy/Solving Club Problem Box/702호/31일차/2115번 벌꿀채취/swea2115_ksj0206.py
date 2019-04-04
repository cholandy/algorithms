import sys;sys.stdin=open('input2.txt','r')

T = int(input())
for t in range(1,T+1):
    # input
    n,m,c = map(int,input().split())
    mapp = [ 0 for _ in range(n)]
    for _ in range(n):
        mapp[_] = list(map(int,input().split()))
    honey=[[0 for _ in range(n)] for _ in range(n)]
    print(honey)
    # 먼저 m과 c에 맞춰 최대 수익을 미리 저장
    honey_max = [ [ 0 for _ in range(n-m+1) ] for _ in range(n) ] # 세로는 바뀌지 않고 가로만 압축된다.
    for i in range(n):
        for j in range(n-m+1):
            # m칸 안에 뽑을 수 있는 최대 수익 찾는 부분
            candys = mapp[i][j:j+m]
            maxx = 0
            for ii in range(1<<m):
                result = 0
                afford = 0
                for jj in range(m):
                    if ii & (1<<jj):
                        result += candys[jj]**2
                        afford += candys[jj]
                else: # 부분집합 만들었으면
                    if result > maxx and afford <= c: # 체크해서
                        maxx = result # 갱신
            honey_max[i][j] = maxx # 부분집합 중 최종 최대값만 저장
 
 
    # 이제 저장해 놓은 정보를 바탕으로 안 겹치게 2개 고르면 됨
    real_max = 0 # 진짜 최종 값
    for row in range(n): # 행은 다돌고
        for col in range(n-m+1): # 열은 적당히
            first = honey_max[row][col]
            for row2 in range(row,n): # 두번쨰 타겟은 첫번쨰 타켓이 있는 행부터 시작
                if row2 == row: # 겹치는 행에 있어서는
                    for col2 in range(col+m,n-m+1): # 겹치지 않도록 범위 조정. 여기서 col+m-1>n-m+1 이면 어차피 안돈다.
                        if first+honey_max[row2][col2] > real_max:
                            real_max = first+honey_max[row2][col2]
                else: # 겹치는 행아니면
                    for col2 in range(n-m+1):
                        if first + honey_max[row2][col2] > real_max: # 클 때만
                            real_max = first + honey_max[row2][col2]  # 갱신
 
    print("#{} {}".format(t,real_max))