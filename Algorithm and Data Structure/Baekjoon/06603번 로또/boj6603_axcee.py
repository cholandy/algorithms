

def recgen(arr, buf, idx) :
    if len(buf) == 6 :
        yield buf
    for i in range(idx, len(arr)) :
        buf.append(arr[i])
        yield from recgen(arr, buf, i+1)
        buf.pop()

while True :
    k = list(map(int, input().split()))
    if k[0] == 0 :
        break
    n, a = k[0], k[1:]
    a.sort()
    for b in recgen(a, [], 0) :
        print(' '.join(str(i) for i in b))
    print('')
