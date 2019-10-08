a = ' '+input()
b = ' '+input()
lcs = [[None]*len(b) for i in range(len(a))]

for i in range(len(a)):
    lcs[i][0] = 0
for j in range(len(b)):
    lcs[0][j] = 0
for i in range(1,len(a)):
    for j in range(1,len(b)):
        if a[i]==b[j]:
            lcs[i][j] = lcs[i-1][j-1]+1
        else:
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1])
print(lcs[-1][-1])

track = []
while i>0 and j>0:
    if a[i]==b[j]:
        track.append(a[i])
        i-= 1
        j-= 1
    elif lcs[i][j-1] > lcs[i-1][j]:
        j-= 1
    else:
        i-= 1
print(''.join(track[::-1]))