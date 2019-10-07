s=[]
for x in input():
    if x=='H':
        s.append(1)
    elif x=='C':
        s.append(12)
    elif x=='O':
        s.append(16)
    elif x=='(':
        s.append(x)
    elif x==')':
        t=0
        while s[-1]!='(':
            t+=s[-1]
            s.pop()
        s.pop()
        s.append(t)
    else:
        t=s[-1]*int(x)
        s.pop()
        s.append(t)
print(sum(s))