T = int(input())
L = list(input())
for i in range(T-1):
    name = input()
    for i in range(len(L)):
        if name[i] != L[i]:
            L[i] = '?'
print(''.join(L))