Q, L = map(int,input().split())
for n in range(L, 101):
    rem = 2*Q - n**2 - n
    x = rem//(2*n)
    if x >= -1 and rem%(2*n) == 0:
        print(*range(x+1, x+n+1))
        break
else: print(-1)