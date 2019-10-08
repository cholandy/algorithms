ans=[-1]*26
word=input()
for i in range(len(word)):
    idx=ord(word[i])-97
    if ans[idx]==-1:
        ans[idx]=i
    else:
        continue
print(*ans)