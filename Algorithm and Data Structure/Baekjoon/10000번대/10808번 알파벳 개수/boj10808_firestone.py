string = input()
ans = [0]*26
for word in string:
    ans[ord(word)-97] += 1
print(*ans)
