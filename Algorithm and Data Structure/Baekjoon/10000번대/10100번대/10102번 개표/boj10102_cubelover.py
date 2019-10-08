import sys
input=sys.stdin.readline
n=int(input())
s=input().strip()
a=b=0
for i in range(n):
    if s[i]=='A':
        a+=1
    else:
        b+=1
if a>b:
    print("A")
elif a<b:
    print("B")
else:
    print("Tie")