def sol(x) :
    n = 1
    while x-n > 0 :
        x -= n
        n += 1
    return (n-x+1, x) if n%2 else (x, n-x+1)

print('{0}/{1}'.format(*sol(int(input()))))