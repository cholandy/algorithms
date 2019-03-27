from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
check = [False]*n
a = []

def solve(cnt):
    if cnt == m:
        print(" ".join(map(str, a)))
        return
    for i in range(n):
        if not check[i]:
            check[i] = True
            a.append(i+1)
            solve(cnt+1)
            a.pop()
            check[i] = False

solve(0)
