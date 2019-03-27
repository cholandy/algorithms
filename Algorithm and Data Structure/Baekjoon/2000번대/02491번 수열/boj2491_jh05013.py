input()
seq = list(map(int,input().split()))
ascm = 1
decm = 1
asc = 1
dec = 1
for i in range(1,len(seq)):
    if seq[i-1] == seq[i]:
        asc+= 1
        dec+= 1
    elif seq[i-1] > seq[i]:
        asc = 1
        dec+= 1
    else:
        asc+= 1
        dec = 1
    ascm, decm = max(ascm, asc), max(decm, dec)
print(max(ascm, decm))