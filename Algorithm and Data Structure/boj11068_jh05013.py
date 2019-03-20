def palinbase(n, b):
    s = []
    while n: s.append(n%b); n//= b
    return s == s[::-1]

for TEST in range(int(input())):
    n = int(input())
    print(int(any(palinbase(n, b) for b in range(2,65))))