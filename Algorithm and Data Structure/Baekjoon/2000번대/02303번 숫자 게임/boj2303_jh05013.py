def best(L):
    res = 0
    for i in range(5):
        for j in range(i+1,5):
            for k in range(j+1,5):
                res = max(res, (L[i]+L[j]+L[k])%10)
    return res

n = int(input())
scores = []
for i in range(n):
    scores.append((best(list(map(int,input().split()))),i+1))
print(max(scores)[1])