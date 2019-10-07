import sys

var = sys.stdin.readline()[:-1]

tp = 'C++'

for i in range(len(var)):
    if(var[i] >= 'A' and var[i] <= 'Z'):
        tp = 'Java'

if(tp == 'C++'):
    var = var.split('_')
    x = False
    for w in var:
        if(len(w) == 0):
            x = True
    if(x):
        print("Error!")
    else:
        print(var[0],end="")
        for w in var[1:]:
            print(chr(ord(w[0])-32)+w[1:],end="")
elif(tp == 'Java'):
    var = var.split('_')
    if(len(var) > 1 or var[0][0] >= 'A' and var[0][0] <= 'Z'):
        print("Error!")
    else:
        for i in range(len(var[0])):
            if(var[0][i] >= 'A' and var[0][i] <= 'Z'):
                print('_'+chr(ord(var[0][i])+32),end="")
            else:
                print(var[0][i],end="")
