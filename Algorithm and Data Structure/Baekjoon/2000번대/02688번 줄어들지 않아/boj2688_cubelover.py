import sys
input=sys.stdin.readline
for tc in range(int(input())):
    r=1
    for i in range(int(input())):
        r*=i+10
        r//=i+1
    print(r)