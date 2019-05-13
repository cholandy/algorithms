s=input().rstrip()
ans=''
for i in range(len(s)):
    if 64<ord(s[i])<91:
        ans+=s[i]
print(ans)
