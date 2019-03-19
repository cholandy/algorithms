for _ in range(int(input())):
    s = input()
    flag = 1
    j = 0
    for x in s:
        if x == '(':
            j += 1
        else:
            j -= 1
        if j < 0:
            flag = 0
            break
    print('YES' if not j and flag else 'NO')