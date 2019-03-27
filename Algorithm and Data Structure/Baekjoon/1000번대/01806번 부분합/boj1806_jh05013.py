n, s = map(int,input().split())
p = list(map(int,input().split()))
minlen = 999999

i = 0
j = 0
cursum = p[0]
if cursum >= s: minlen = 1
while i < n:
    if j == n-1:
        i+= 1
        cursum-= p[i-1]
    elif i == j:
        j+= 1
        cursum+= p[j]
    elif cursum <= s:
        j+= 1
        cursum+= p[j]
    else:
        i+= 1
        cursum-= p[i-1]
    if cursum >= s: minlen = min(minlen, j-i+1)
print(minlen if minlen != 999999 else 0)