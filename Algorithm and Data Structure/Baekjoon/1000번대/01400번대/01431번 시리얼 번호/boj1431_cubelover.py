n=int(input())
a=[]
for i in range(n):
    s=input()
    t=0
    for j in range(len(s)):
        if 48<=ord(s[j])<58:
            t+=ord(s[j])-48
    a.append([len(s),t,s])
a.sort()
for i in range(n):
    print(a[i][2])