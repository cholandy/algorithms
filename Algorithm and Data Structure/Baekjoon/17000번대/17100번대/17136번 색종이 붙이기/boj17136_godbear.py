import sys;sys.stdin=open('input2.txt','r')

def dfs(pos, cnt):
    global mincnt, blocks, maps
    if 0 <= mincnt <= cnt:
        return
    if not pos:
        if cnt < mincnt or mincnt < 0:
            mincnt = cnt
    flag = 0
    for y in range(10):
        for x in range(10):
            if maps[y][x]:
                flag += 1
                break
        if maps[y][x]:
            break
    if not flag:
        return
    for i in range(5, 0, -1):
        if blocks[i]:
            ey = y + i
            ex = x + i
            changed = []
            can = True
            for ny in range(y, ey):
                for nx in range(x, ex):
                    if 0 <= ny < 10 and 0 <= nx < 10:
                        if maps[ny][nx]:
                            changed.append((ny, nx))
                            maps[ny][nx] = 0
                        else:
                            can = False
                            break
                    else:
                        can = False
                        break
                if not can:
                    break
            if can:
                blocks[i] -= 1
                pos -= i ** 2
                dfs(pos, cnt+1)
                pos += i ** 2
                blocks[i] += 1
            for j in changed:
                maps[j[0]][j[1]] = 1

for tc in range(int(input())):
    maps = [list(map(int, input().split())) for _ in range(10)]
    pos =0
    blocks = [0, 5, 5, 5, 5, 5]
    for i in range(10):
        for j in range(10):
            if maps[i][j]:
                pos += 1
    mincnt = -1
    dfs(pos, 0)
    print("#{}".format(tc+1),end=' ')
    print(mincnt)