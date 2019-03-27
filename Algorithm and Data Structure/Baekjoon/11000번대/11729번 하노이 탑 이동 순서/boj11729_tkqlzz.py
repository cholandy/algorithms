def hanoi(n, a, b, c):
    stack = []
    res = ''
    while True:
        while n > 1:
            stack.append((n, a, b, c))
            n -= 1
            b, c = c, b
        res += a + ' ' + c + '\n'
        if stack:
            n, a, b, c = stack.pop()
            res += a + ' ' + c + '\n'
            n -= 1
            a, b = b, a
        else:
            break
    return res

n = int(input())
print(2 ** n - 1)
print(hanoi(n, '1', '2', '3'))