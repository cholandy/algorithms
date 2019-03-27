N=int(input())
num = 666
turn = 1

while 1:
    if turn == N:break
    num+=1
    cn=six=0
    cn=num
    while cn:
        tmp=0
        tmp = cn % 10
        if tmp==6: six+=1
        elif six<3: six=0
        cn//=10
    if six>=3: turn +=1
print(num)
