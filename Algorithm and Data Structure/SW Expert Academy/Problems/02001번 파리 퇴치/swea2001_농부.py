# n범위를 가진 감지기로 리스트L에서 find, 최댓값 return
def finder(L, n):
    ans = 0
    max = -100
    for i in range(n-1, len(L)):
        for j in range(n-1, len(L)):
            for k in range(i, i-n, -1):
                for l in range(j, j-n, -1):
                    ans = L[k][l]+ans
            if ans > max:
                max = ans
            ans = 0
    return(max)


for t in range(int(input())):
    N = []
    n, m = input().split()
    for i in range(int(n)):
        N.append(list(map(int, input().split())))
    print("#"+str(t+1), finder(N, int(m)))
    N.clear()
