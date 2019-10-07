stack = []
line = input()
for c in line:
    if c == '(' or c == '[':
        stack.append(c)
    elif c == ')':
        sum = 0
        while True:
            if len(stack) == 0 or stack[-1] == '[':
                print(0)
                exit(0)
            elif stack[-1] != '(':
                sum += stack.pop()
            else:
                stack.pop()
                if sum == 0:
                    stack.append(2)
                else:
                    stack.append(sum*2)
                break
    elif c == ']':
        sum = 0
        while True:
            if len(stack) == 0 or stack[-1] == '(':
                print(0)
                exit(0)
            elif stack[-1] != '[':
                sum += stack.pop()
            else:
                stack.pop()
                if sum == 0:
                    stack.append(3)
                else:
                    stack.append(sum*3)
                break
    else:
        print(0)
        exit(0)

sum = 0
if len(stack) == 0:
    print(0)
    exit(0)
for n in stack:
    if n == '(' or n == '[':
        print(0)
        exit(0)
    else:
        sum += n

print(sum)