def get_lbs(n, arr):
    """
    first, I got two LIS, left to right LIS and right to left LIS.
    second, sum_ LIS result(increase_dp[i] + decrease_dp[i])
    """
    increase_dp = [1 for i in range(n)]
    decrease_dp = [1 for i in range(n)]

    for i in range(n):
        for j in range(i):
            if arr[j] < arr[i]:
                increase_dp[i] = max(increase_dp[i], increase_dp[j] + 1)

    for i in range(n - 1, -1, -1):
        for j in range(n - 1, i, -1):
            if arr[j] < arr[i]:
                decrease_dp[i] = max(decrease_dp[i], decrease_dp[j] + 1)

    ret_value = 0
    for i in range(n):
        sum_ = increase_dp[i] + decrease_dp[i]
        if ret_value < sum_:
            ret_value = sum_

    return ret_value - 1


def main():
    n = int(input())
    arr = [int(x) for x in input().split()]
    ret = get_lbs(n, arr)
    print(ret)


if __name__ == "__main__":
    main()