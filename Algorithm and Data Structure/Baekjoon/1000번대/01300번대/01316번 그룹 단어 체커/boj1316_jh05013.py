ans = 0
for line in range(int(input())):
    s = input()
    if len(s) == 1:
        ans+= 1
        continue
    used = set()
    good = True
    used.add(s[0])
    for i in range(1,len(s)):
        if s[i] != s[i-1]:
            if s[i] in used:
                good = False
                break
            used.add(s[i])
    if good:
        ans+= 1
print(ans)