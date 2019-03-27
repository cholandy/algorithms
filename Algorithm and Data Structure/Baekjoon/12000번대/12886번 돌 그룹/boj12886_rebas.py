from collections import deque

def bfs():
    q = deque()
    q.append((A, B))
    check[A][B] = True
    while q:
        x, y = q.popleft()
        z = D-x-y
        if x == y == z:
            print(1)
            return
        for a, b in (x, y), (x, z), (y, z):
            if a < b:
                b -= a
                a += a
            elif a > b:
                a -= b
                b += b
            else:
                continue
            c = D-a-b
            X = min(a, b, c)
            Y = max(a, b, c)
            if not check[X][Y]:
                q.append((X, Y))
                check[X][Y] = True
    print(0)

def solve():
    if D % 3:
        print(0)
        return
    else:
        bfs()

A, B, C = map(int, input().split())
D = A+B+C
check = [[False]*D for _ in range(D)]
solve()


