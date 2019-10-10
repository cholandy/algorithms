import sys
sys.stdin = open('input.txt', 'r')


def up_down(num):
    if num % 1 >= 0.5:
        return num+1-(num % 1)
    else:
        return num-(num % 1)


for _ in range(int(input())):
    ans = 0
    mmax = 0
    mmin = float('INF')
    nums = list(map(int, input().split()))
    for i in range(10):
        mmax = max(mmax, nums[i])
        mmin = min(mmin, nums[i])
        ans += nums[i]
    ans = ans - mmax - mmin
    ans /= 8
    ans = int(up_down(ans))
    # print(mmax, mmin)
    print("#{} {}".format(_+1, ans))
