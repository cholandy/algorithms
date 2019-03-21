n = int(input())
ans = [int(input())]
for i in range(2,n+1):
    b = [0]*(i)
    line = list(map(int, input().split()))
    b[0] = ans[0]+line[0]
    for j in range(1,i-1):
        b[j] = max(ans[j-1], ans[j])+line[j]
    b[-1] = ans[-1]+line[-1]
    ans = b[:]
print(max(ans))