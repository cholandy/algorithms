while 1:
    lines = int(input())
    if lines == 0:
        break
    cur = 0
    for i in range(lines):
        line = input()
        a = line.find(' ',cur)
        if a == -1:
            a = max(len(line), cur)
        cur = a
    print(cur+1)