def change(A, B):
    L = A[:]
    press = 0
    for i in range(1, n):
        if L[i-1] == B[i-1]: continue
        press+= 1
        for j in range(i-1, i+2):
            if j < n: L[j] = 1-L[j]
    return press if L == B else float('inf')

n = int(input())
A = list(map(int,input()))
B = list(map(int,input()))
res = change(A, B)
A[0] = 1-A[0]
A[1] = 1-A[1]
res = min(res, 1+change(A, B))
print(res if res != float('inf') else -1)