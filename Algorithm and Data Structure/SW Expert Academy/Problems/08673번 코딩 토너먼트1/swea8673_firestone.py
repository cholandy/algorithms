import sys
sys.stdin = open('C:\\Users\\woosa\\Desktop\\algorithms\\input.txt', 'r')

for _ in range(int(input())):
    K = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    cnt = 1 << (K-1)
    while cnt >= 1:
        temp = []
        for i in range(cnt):
            ans += abs(arr[2*i]-arr[2*i+1])
            temp.append(max(arr[2*i], arr[2*i+1]))
        arr = temp
        cnt //= 2
    print("#{} {}".format(_+1, ans))
