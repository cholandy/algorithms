s = input().replace("()","L")
level = 0
total = 0
#print(s)
for c in s:
    if c == "(":
        level+= 1
    elif c == ")":
        level-= 1
        total+= 1
    else:
        total+= level
    #print(c,level,total)
print(total)