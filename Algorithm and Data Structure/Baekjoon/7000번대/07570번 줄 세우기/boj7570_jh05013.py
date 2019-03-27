n = int(input())
label = list(map(int,input().split()))
index = [0]*(n)
for i in range(n):
    index[label[i]-1] = i
index.append(-1)
res = 0
cur = 1
for i in range(n):
    if index[i] < index[i+1]: cur+= 1
    else:
        res = max(res, cur)
        cur = 1
print(n-res)