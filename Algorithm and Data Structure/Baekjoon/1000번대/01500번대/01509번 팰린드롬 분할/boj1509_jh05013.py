d = input()
n = len(d)
palin = [[None]*n for i in range(n)]
minsp = [2500]*(n+1)
# palin[i][j] == True iff d[i:j+1] is palindrome or i>j
# minsp[i] == minimum split of d[:i]

def get(L,y,x):
    try:
        return L[y][x]
    except:
        return 1

for j in range(n):
    for i in range(n):
        if i>=j:
            palin[i][j] = True
        elif d[i]==d[j] and get(palin,i+1,j-1):
            palin[i][j] = True
        else:
            palin[i][j] = False

minsp[0] = 0
for i in range(1,n+1):
    for j in range(i):
        if palin[j][i-1]:
            minsp[i] = min(minsp[i], minsp[j]+1)
print(minsp[-1])