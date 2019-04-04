import sys;sys.stdin=open('input2.txt','r')


def m_honey(y, x, idx, sum, money):
    if sum > C: return
    if idx == M:
        d[y][x-idx] = max(d[y][x-idx], money)
        return
    m_honey(y, x+1, idx+1, sum+honey[y][x], money+(honey[y][x]**2))
    m_honey(y, x+1, idx+1, sum, money)
 
T = int(input())
for _ in range(T):
    N, M, C = map(int, input().split())
    honey = [list(map(int, input().split())) for _ in range(N)]
    d = [[0]*11 for _ in range(10)]
 
    for i in range(N):
        for j in range(N-M+1):
            m_honey(i, j, 0, 0, 0)
            d[i][10] = max(d[i][10], d[i][j])
 
    ans = 0
    max1 = max2 = 0
    for i in range(N):
        f = 0
        for j in range(N-M+1):
            for k in range(N-2*M-j+1):
                ans = max(ans, d[i][j] + d[i][j+M+k])
 
        if max1 < d[i][10]:
            max2 = max1
            max1 = d[i][10]
            f = 1
        if f == 0 and max2 < d[i][10]:
            max2 = d[i][10]
    ans = max(ans, max1 + max2)
    print("#%d %d" % (_+1, ans))