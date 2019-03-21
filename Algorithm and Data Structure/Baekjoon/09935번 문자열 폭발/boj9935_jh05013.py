def suffix(b, L):
    if len(L) < len(b): return False
    return all(L[~i] == b[~i] for i in range(len(b)))

s = input()
bomb = input()
stack = []
for c in s:
    stack.append(c)
    while suffix(bomb, stack):
        for i in range(len(bomb)): stack.pop()
print(''.join(stack) if stack else "FRULA")