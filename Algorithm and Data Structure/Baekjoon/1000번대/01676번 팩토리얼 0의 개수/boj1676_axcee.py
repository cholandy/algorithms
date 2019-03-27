def solve(n) :
    s, e = 0, 5
    while e <= n :
        s += n//e
        e *= 5
    return s

print(solve(int(input())))