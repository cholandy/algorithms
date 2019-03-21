def rec(n) :
    res = [0, 0]
    for i in range(2, n+1) :
        mn = res[i-1] + 1
        if i % 3 == 0 :
            mn = min(mn, res[i//3] + 1)
        if i % 2 == 0 :
            mn = min(mn, res[i//2] + 1)
        res.append(mn)
    return res[-1]

print(rec(int(input())))