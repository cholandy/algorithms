for i in range(int(input())):
    n, k = list(map(int, input().split()))
    r = [''.join(list(input().split())) for l in range(n)]
    c = [''.join(r[b][c] for b in range(n)) for c in range(n)]
    s = 0
    if k < n:
        for m in range(n):
            if r[m][0] == '1':
                if r[m][0:k] == '1'*k and r[m][k] == '0':
                    s += 1
            for x in range(n-k):
                if x < n-k-1:
                    if r[m][x] == '0' and r[m][x+1:x+k+1] == '1'*k and r[m][x+k+1] == '0':
                        s += 1
                else:
                    if r[m][x] == '0' and r[m][x+1:] == '1'*k:
                        s += 1
            if c[m][0] == '1':
                if c[m][0:k] == '1'*k and c[m][k] == '0':
                    s += 1
            for y in range(n-k):
                if y < n-k-1:
                    if c[m][y] == '0' and c[m][y+1:y+k+1] == '1'*k and c[m][y+k+1] == '0':
                        s += 1
                else:
                    if c[m][y] == '0' and c[m][y+1:] == '1'*k:
                        s += 1
    else:
        for z in range(n):
            if r[z] == '1'*k:
                s += 1
            if c[z] == '1'*k:
                s += 1
    print(f'#{i+1} {s}')
