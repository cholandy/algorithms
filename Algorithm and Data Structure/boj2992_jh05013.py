s = list(input())
for i in range(len(s)-2, -1, -1):
    if s[i] < s[i+1]: break
else:
    print(0)
    exit()
for j in range(len(s)-1, i, -1):
    if s[j] > s[i]: break
s[i], s[j] = s[j], s[i]
s[i+1:] = s[:i:-1]
print(''.join(s))

