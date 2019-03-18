from collections import deque



def available(odd, N, grid, bishop, y, x):
    if grid[y][x] != 1 or (y + x) % 2 != odd:
        return False
    for y1, x1 in bishop:
        if y1 - x1 == y - x or y1 + x1 == y + x:
            return False
    return True


def next_bishop(odd, N, grid, bishop, y, x):
    for x1 in range(x + 1, N):
        if available(odd, N, grid, bishop, y, x1):
            return y, x1
    for y1 in range(y + 1, N):
        for x1 in range(N):
            if available(odd, N, grid, bishop, y1, x1):
                return y1, x1
    return -1, -1


def get_max_bishop(N, grid, odd):
    queue = deque()
    y, x = next_bishop(odd, N, grid, [], 0, -1)
    if y < 0:
        return 0
    bishop = [(y, x)]
    ans = 0
    while True:
        ans = max(ans, len(bishop))
        y, x = bishop[-1]
        y1, x1 = next_bishop(odd, N, grid, bishop, y, x)
        if y1 >= 0:
            bishop += [(y1, x1)]
            continue
        while bishop:
            y, x = bishop.pop()
            y1, x1 = next_bishop(odd, N, grid, bishop, y, x)
            if y1 >= 0:
                bishop += [(y1, x1)]
                break
        else:
            break
    return ans


N = int(input())
grid = [[int(x) for x in input().split()] for _ in range(N)]
print(get_max_bishop(N, grid, 0) + get_max_bishop(N, grid, 1))
