input=__import__('sys').stdin.readline
N=int(input())
if N==4 or N==7:print(-1)  
a,b=N//5,N%5
while a>-1:
    if b==0: print(a);break
    c,d=b//3,b%3
    if d==0:print(a+c);break
    else:
        a-=1
        b+=5