import sys
input = sys.stdin.readline
for _ in range(int(input())):
    a, b = map(int, input().split())
    print(int(((b - a) * 4 - .5) ** .5))