s = input()
print(len(s) if s != s[::-1] else len(s) - 1 if s[1:] != s[1:][::-1] else -1)
