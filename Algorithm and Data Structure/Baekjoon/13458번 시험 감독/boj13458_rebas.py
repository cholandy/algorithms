n, ans = int(input()), 0
a = list(map(int, input().split()))
b, c = map(int, input().split())

for i in range(n):
    if a[i] >= b:
        d = a[i]-b
        ans += d//c if d%c == 0 else d//c+1
print(ans+n)
