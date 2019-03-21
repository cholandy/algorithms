import sys
input = lambda: sys.stdin.readline().rstrip()

tc = int(input())
for t in range(tc) :
    cmd = input()
    p, q = 0, int(input())
    arr = input()[1:-1].split(',')
    for c in cmd :
        if c == 'R' :
            p, q = q, p
        elif p < q :
            p += 1;
        elif p > q :
            p -= 1
        else :
            print('error')
            break
    else :
        if p > q :
            arr = arr[q:p]
            arr.reverse()
        else :
            arr = arr[p:q]
        print('['+','.join(arr)+']')