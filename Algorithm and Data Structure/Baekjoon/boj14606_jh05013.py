def fun(x):
    if x in memo: return memo[x]
    half = x//2
    res = fun(half) + fun(x-half) + half*(x-half)
    memo[x] = res
    return res
memo = {1:0}

n = int(input())
print(fun(n))