n = int(input())
left = list(map(int,input().split()))
right = list(map(int,input().split()))
opt = [[0]*(n+1) for i in range(n+1)] # best score, starting from i, j cards

for i in range(1,n+1):
    for j in range(1,n+1):
        cur = max(opt[i-1][j], opt[i-1][j-1])
        if left[-i] > right[-j]:
            cur = max(cur, opt[i][j-1]+right[-j])
        opt[i][j] = cur
print(opt[-1][-1])