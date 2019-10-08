def check(i):
    ans1 = -1
    for j in range(n+2):
        l = i-j-1; r = i+j+1
        if not (0<=l and r<n): ans1 = 2*j+1; break
        if s[l] != s[r] or s[r] >= s[r-1]: ans1 = 2*j+1; break
    if i+1 == n or s[i] != s[i+1]: return ans1
    ans2 = -1
    for j in range(n+2):
        l = i-j-1; r = i+j+2
        if not (0<=l and r<n): ans2 = 2*j+2; break
        if s[l] != s[r] or s[r] >= s[r-1]: ans2 = 2*j+2; break
    return max(ans1, ans2)

n = int(input())
s = list(map(int,input().split()))
print(max(map(check, range(n))))