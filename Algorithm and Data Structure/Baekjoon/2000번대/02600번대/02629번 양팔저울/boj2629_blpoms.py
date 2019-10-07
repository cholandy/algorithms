n = int(input())
arr = tuple(map(int, input().split()))
m = int(input())
t = tuple(map(int, input().split()))
for i in t:
    dp = {i}
    b = True
    for k in arr:
        temp = set()
        for j in dp:
            temp.update({j-k, j+k, j})
        dp.update(temp)
        if 0 in dp: print('Y', end=' ');b=False;break
    if b: print('N', end=' ')