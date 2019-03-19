MIS = lambda: map(int,input().split())
for TEST in range(int(input())):
    n, m = MIS()
    A = sorted(MIS())
    B = sorted(MIS())
    ans = 0
    j = 0
    for i in range(n):
        while j < m and B[j] < A[i]: j+= 1
        ans+= j
    print(ans)