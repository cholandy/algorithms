def eql(s):
    if len(s)%2: return s
    hf = len(s)//2
    left = eql(s[:hf]); right = eql(s[hf:])
    return min(left+right, right+left)

a = input()
b = input()
print("YES" if eql(a) == eql(b) else "NO")