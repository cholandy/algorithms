n,m = map(int,input().split())
a = list(map(int,input().split()))
s = [0]
for i in range(n):
    s.append(s[-1]+a[i])
i = 0
j = 0
ans = 0
while 1:
    if j >= len(s):
        break
    elif s[j]-s[i] == m:
        ans+= 1
        j+= 1
    elif s[j]-s[i] > m:
        i+= 1
    else:
        j+= 1
print(ans)