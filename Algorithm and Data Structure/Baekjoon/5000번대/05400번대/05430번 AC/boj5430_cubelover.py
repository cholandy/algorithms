import sys
input = sys.stdin.readline

for _ in range(int(input())):
    i = j = k = 0
    for s in input().strip():
        if s == 'R':
            k ^= 1
        elif k:
            j -= 1
        else:
            i += 1
    n = int(input())
    j += n
    a = input()
    assert a[0] == '['
    assert a[-2] == ']'
    assert a[1] != ','
    assert a[-3] != ','
    assert a.find(',,') == -1
    for x in a[1:-2]:
        assert x in '0123456789,'
    if not a[1:-2]:
        a = []
    else:
        a = list(map(int, a[1:-2].split(',')))
    if i > j:
        print('error')
    else:
        a = a[i:j]
        if k:
            a = a[::-1]
        print('[' + ','.join(map(str, a)) + ']')
