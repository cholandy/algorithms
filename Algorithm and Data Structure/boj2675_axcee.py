tc = int(input())
for t in range(tc) :
    r, s = input().split()
    print(''.join(x*int(r) for x in s))
