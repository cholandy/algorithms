n = int(input())
if n%2 == 1:
    print(0)
else:
    ans = [1,3]
    for i in range(n//2-1):
        ans.append(4*ans[-1]-ans[-2])
    print(ans[n//2])