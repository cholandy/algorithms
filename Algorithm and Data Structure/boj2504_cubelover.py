a=input()
s=[]
flag=1
for i in range(len(a)):
    if a[i]=='(' or a[i]=='[':
        s.append(a[i])
    elif a[i]==')':
        t=0
        while len(s):
            if s[len(s)-1]=='(':
                break
            elif s[len(s)-1]=='[':
                flag=0
            else:
                t+=s[len(s)-1]
            s.pop()
        if len(s):
            s.pop()
        else:
            flag=0
        if t==0:
            t=1
        s.append(t*2)
    else:
        t=0
        while len(s):
            if s[len(s)-1]=='[':
                break
            elif s[len(s)-1]=='(':
                flag=0
            else:
                t+=s[len(s)-1]
            s.pop()
        if len(s):
            s.pop()
        else:
            flag=0
        if t==0:
            t=1
        s.append(t*3)
for i in range(len(s)):
    if type(s[i]) is str:
        flag=0
if flag:
    print(sum(s))
else:
    print(0)