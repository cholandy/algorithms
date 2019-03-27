from sys import stdin
input = stdin.readline
stack = []
n = int(input())
for i in range(n):
    s = input().rstrip()
    if s[:4] == "push":
        stack.append(int(s[5:]))
    elif s == "pop":
        print(stack.pop() if stack else -1)
    elif s == "size":
        print(len(stack))
    elif s == "empty":
        print(0 if stack else 1)
    elif s == "top":
        print(stack[-1] if stack else -1)