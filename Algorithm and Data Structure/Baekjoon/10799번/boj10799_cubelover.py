s = input()
j = r = 0
for i in range(len(s)):
    if s[i] == '(':
        j += 1
    elif s[i - 1] == '(':
        j -= 1
        r += j
    else:
        j -= 1
        r += 1
print(r)