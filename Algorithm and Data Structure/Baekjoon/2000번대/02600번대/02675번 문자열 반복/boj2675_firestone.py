for tc in range(int(input())):
    r, s = input().split()
    ans=''
    for i in range(len(s)):
        ans+=s[i]*int(r)
    print(ans)
