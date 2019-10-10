N = int(input())
for num in range(1, N+1):
    a = list(str(num))
    cnt = 0
    for i in a:
        if i in ['3', '6', '9']:
            cnt += 1
    if cnt:
        print("{}".format('-'*cnt), end=' ')
    else:
        print("{}".format(num), end=' ')
