from sys import stdin
input = stdin.readline
c = ([int(input()) for i in range(int(input()))])
c.sort(reverse = True)
res = sum(c)
for i in range(2,len(c),3):
    res-= c[i]
print(res)