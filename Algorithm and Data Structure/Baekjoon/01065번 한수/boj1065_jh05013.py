def yes(n):
    if n<100:
        return True
    s = str(n)
    return int(s[1])*2 == int(s[0])+int(s[2])

n = int(input())
print(sum([yes(i) for i in range(1,n+1)]))