from bisect import bisect_left as BL, bisect_right as BR
input = __import__('sys').stdin.readline


def MIS(): return map(int, input().split())


n = int(input())
X = [tuple(MIS()) for i in range(n)]
m = int(input())
Y = [tuple(MIS()) for i in range(m)]
a = int(input())
b = int(input())

YACC = [Y[0][1]]
for i in range(1, m):
    YACC.append(YACC[-1] + Y[i][1])
YACC.append(0)

ans = 0
for x, vx in X:
    l = BL(Y, (x+a, -10**12))
    r = BR(Y, (x+b, 10**12))
    ans += vx * (YACC[r-1] - YACC[l-1])
print(ans)
