n = int(input())
p = list(map(int,input().split()))
endsum = [0]*n # end with [i]
stsum = [0]*n # start with [i]

e = 0
s = 0
for i in range(n):
    e = max(e,0) + p[i]; endsum[i] = e
    s = max(s,0) + p[~i]; stsum[~i] = s

res = max(endsum)
for i in range(1, n-1):
    res = max(res, endsum[i-1]+stsum[i+1])
print(res)