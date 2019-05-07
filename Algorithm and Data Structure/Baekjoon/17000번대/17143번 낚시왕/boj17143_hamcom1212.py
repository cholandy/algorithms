import sys
from collections import *
from itertools import *

sys.setrecursionlimit(1000000)


UP, DOWN, RIGHT, LEFT = 1, 2, 3, 4


def get_inputs():
    return list(map(int, input().split()))


def catch(field, r, c, pos):
    for y in range(r):
        if field[y][pos]:
            sz = field[y][pos][2]
            field[y][pos] = None
            return sz
    return 0


def print_field(field, r, c):
    for y in range(r):
        for x in range(c):
            if field[y][x]:
                print(f'{field[y][x]}\t', end='')
            else:
                print('\t\t', end='')
        print()


def shark_move(field, r, c):
    new_field = [[None] * c for _ in range(r)]

    for y in range(r):
        for x in range(c):
            if not field[y][x]:
                continue

            speed, direction, size = field[y][x]
            ny, nx, distance = y, x, speed
            if direction in [UP, DOWN]:
                while True:
                    if direction == UP:
                        move = min(distance, ny)
                        ny -= move
                    else:
                        move = min(distance, r-1-ny)
                        ny += move

                    distance -= move
                    if distance == 0:
                        break
                    direction = DOWN if direction == UP else UP

            elif direction in [LEFT, RIGHT]:
                while True:
                    if direction == LEFT:
                        move = min(distance, nx)
                        nx -= move
                    else:
                        move = min(distance, c-1-nx)
                        nx += move

                    distance -= move
                    if distance == 0:
                        break
                    direction = LEFT if direction == RIGHT else RIGHT

            if not new_field[ny][nx] or (new_field[ny][nx] and new_field[ny][nx][2] < size):
                new_field[ny][nx] = (speed, direction, size)

    for y in range(r):
        for x in range(c):
            field[y][x] = new_field[y][x]


def main():
    r, c, m = get_inputs()
    field = [[None] * c for _ in range(r)]

    for _ in range(m):
        y, x, s, d, z = get_inputs()

        if d in [UP, DOWN]:
            s = s % ((r-1) * 2)
        else:
            s = s % ((c-1) * 2)

        field[y-1][x-1] = (s, d, z)

    total = 0
    for pos in range(c):
        # print_field(field, r, c)
        # print('------------')
        total += catch(field, r, c, pos)
        shark_move(field, r, c)
        # print_field(field, r, c)
        # print('------------')

    print(total)

main()
