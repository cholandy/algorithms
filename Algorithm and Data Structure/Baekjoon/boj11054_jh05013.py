input()
size = list(map(int, input().split()))
rsize = size[::-1]
inc = []
dec = []
for i in range(len(size)):
    cur = 1
    for j in range(i):
        if size[j] < size[i]:
            cur = max(cur, inc[j]+1)
    inc.append(cur)
    cur = 1
    for j in range(i):
        if rsize[j] < rsize[i]:
            cur = max(cur, dec[j]+1)
    dec.append(cur)
dec.reverse()
print(max(inc[i]+dec[i]-1 for i in range(len(inc))))