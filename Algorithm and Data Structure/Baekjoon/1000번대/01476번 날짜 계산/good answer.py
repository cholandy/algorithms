# import sys
# sys.stdin = open('input.txt','r')

n, m, l = map(int, input().split())
a = b = c = i = 1
while a != n or b != m or c != l:
    a, b, c = a % 15 + 1, b % 28 + 1, c % 19 + 1
    i += 1
print(i)