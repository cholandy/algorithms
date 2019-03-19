from sys import stdin
input = stdin.readline
n = int(input())
stack = []
ans = []
nextnum = 1

for i in range(n):
    target = int(input())
    while nextnum <= target:
        stack.append(nextnum)
        ans.append("+")
        nextnum+= 1
    if stack[-1] == target:
        stack.pop()
        ans.append('-')
if stack:
    print("NO")
else:
    for i in ans:
        print(i)