L = []
for i in range(3000000):
    if '666' in str(i): L.append(i)
print(L[int(input())-1])