import sys
sys.stdin = open('input.txt', 'r')

for _ in range(int(input())):
    ans = 0
    N = int(input())
    for i in range(1, N+1):
        if i % 2 == 0:
            ans -= i
        else:
            ans += i
    print('#{} {}'.format(_+1, ans))
