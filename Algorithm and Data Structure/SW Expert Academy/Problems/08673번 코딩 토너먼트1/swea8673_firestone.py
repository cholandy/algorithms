for _ in range(int(input())):
    K = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    cnt = 1 << (K-1)
    while cnt >= 1:
        for i in range(cnt):
            ans += abs(arr[2*i]-arr[2*i+1])
        cnt //= 2
    print("#{} {}".format(_+1, ans))
