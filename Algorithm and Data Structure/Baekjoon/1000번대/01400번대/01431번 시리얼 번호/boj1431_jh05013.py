def value(s):
    num = 0
    for c in s:
        if '0' <= c <= '9':
            num+= int(c)
    return (len(s), num, s)

n = int(input())
guitar = [input() for i in range(n)]
guitar.sort(key = value)
for g in guitar:
    print(g)