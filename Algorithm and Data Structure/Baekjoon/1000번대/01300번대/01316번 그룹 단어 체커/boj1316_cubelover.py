r=0
for tc in range(int(input())):
    s=input()
    n=len(s)
    d=[0 for i in range(26)]
    flag=1
    for i in range(1,n):
        if s[i]!=s[i-1]:
            d[ord(s[i-1])-97]=1
        if d[ord(s[i])-97]:
            flag=0
            break
    r+=flag
print(r)