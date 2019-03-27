n = int(input())
A = list(map(int,input().split()))
step = 0
i = 0
j = 0

while 1:
    if i>j:
        print(-1)
        break
    if j>=n-1:
        print(step)
        break
    step+= 1
    i,j = j+1, max([j]+[c+A[c] for c in range(i,j+1)])

