import sys
sys.stdin = open('input.txt', 'r')

for _ in range(int(input())):
    ans = 0
    N, K = map(int, input().split())

    print("#{} {}".format(_+1, ans))
