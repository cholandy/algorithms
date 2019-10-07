from itertools import combinations
n = int(input())
tenCr = [0,9,45,120,210,252,210,120,45,10,1]
i = 0

if n < 10:
    print(n)
else:
    while i != 11 and n > tenCr[i]:
        n-= tenCr[i]
        i+= 1
    if i == 11:
        print(-1)
    else:
        L = list(combinations('9876543210',i))
        print(''.join(L[-n]))