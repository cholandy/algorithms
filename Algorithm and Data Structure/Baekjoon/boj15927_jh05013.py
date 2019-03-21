def palin(s):
    return s == s[::-1]

s = input()
if not palin(s): print(len(s))
elif not palin(s[:-1]): print(len(s)-1)
else: print(-1)