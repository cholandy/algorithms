import sys;sys.stdin=open('input1.txt','r')
input=__import__('sys').stdin.readline

def BitPrint(i):
    for j in range(3,-1,-1):
        print('1' if (i&(1<<j)) else '0', end="")
     
for tc in range(int(input())):
    a,b=list(input().split())
    x=int(b,16)
    # print(f'#{tc+1} ', end='')
    # for i in range(3*int(a), -1, -4):
    #     BitPrint(x>>i)
    #     print(end='')
    print(f'#{tc+1} ', end='')
    if b[0]=='1':
        print('000', end='')
    elif b[0]=='2' or b[0]=='3':
        print('00', end='')
    elif b[0]=='4' or b[0]=='5' or b[0]=='6' or b[0]=='7':
        print('0', end='')
    print(bin(x)[2:])