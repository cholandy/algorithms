s = input()
if "a" <= s[0] <= "z" and "_" not in s:
    res = ''
    for c in s:
        if "a" <= c <= "z": res+= c
        else: res+= "_"+c.lower()
    print(res)
elif s.islower() and "_" not in s[0]+s[-1] and "__" not in s:
    res = ''
    for w in s.split("_"):
        if res: res+= w.capitalize()
        else: res+= w
    print(res)
else: print("Error!")