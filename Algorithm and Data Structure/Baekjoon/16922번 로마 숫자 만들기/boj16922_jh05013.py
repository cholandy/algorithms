n = int(input())
ns = set()
for I in range(n+1):
    for V in range(n-I+1):
        for X in range(n-I-V+1):
            L = n-I-V-X
            ns.add(I + 5*V + 10*X + 50*L)
print(len(ns))