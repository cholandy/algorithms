import sys
input=sys.stdin.readline
a=set()
for tc in range(int(input())):
    x,y=input().split()
    if y=="enter":
        a.add(x)
    else:
        a.remove(x)
for x in sorted(a)[::-1]:
    print(x)