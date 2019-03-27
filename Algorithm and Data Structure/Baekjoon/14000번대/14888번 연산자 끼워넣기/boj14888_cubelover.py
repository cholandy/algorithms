n = int(input())
a = list(map(int, input().split()))
w, x, y, z = map(int, input().split())
mx = -2e9
mn = 2e9
def f(i, t, w, x, y, z):
    global mx, mn
    if i == n:
        if t > mx:
            mx = t
        if t < mn:
            mn = t
        return
    if w:
        f(i + 1, t + a[i], w - 1, x, y, z)
    if x:
        f(i + 1, t - a[i], w, x - 1, y, z)
    if y:
        f(i + 1, t * a[i], w, x, y - 1, z)
    if z and a[i]:
        f(i + 1, t // a[i] if t > 0 else -(-t // a[i]), w, x, y, z - 1)
f(1, a[0], w, x, y, z)
print(mx)
print(mn)
