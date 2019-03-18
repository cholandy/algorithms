s = input()
ans = [0]*len(s)
if s[-1] != '0':
    ans[-1] = 1
if len(s)>1 and s[-2] != '0':
    ans[-2] = ans[-1]
    if int(s[-2:]) <= 34:
        ans[-2]+= 1
for i in range(len(s)-3, -1, -1):
    if s[i] != '0':
        ans[i] = ans[i+1]
        if int(s[i:i+2]) <= 34:
            ans[i]+= ans[i+2]
print(ans[0])