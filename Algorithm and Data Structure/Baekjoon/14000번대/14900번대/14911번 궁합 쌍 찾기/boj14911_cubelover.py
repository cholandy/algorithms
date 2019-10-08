a = sorted(map(int, input().split()))
b = int(input())
s = set()
for i in range(len(a)):
    for j in range(i+1, len(a)):
        if a[i] + a[j] == b:
            s.add((a[i], a[j]))
for x, y in sorted(s):
    print(x, y)
print(len(s))