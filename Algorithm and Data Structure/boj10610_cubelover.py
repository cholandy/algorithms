s=list(input())
s.sort()
t=0
for i in range(len(s)):
    t+=ord(s[i])-48
if t%3 or s[0]!='0':
    print(-1)
else:
    print(''.join(s[::-1]))