import sys
sys.stdin = open("C:/Users/student/Desktop/asdf/Algorithm and Data Structure/01210번 Ladder1/input.txt", "r")

def check(x, y):
    if x < 0 or x > 99 : return False
    if y < 0 or y > 99 : return False

    if mat[x][y] : return True
    else : return False

def solve( ):
    s = 0
    while True:
        if mat[99][s] == 2: break
        s += 1

    x = 99
    y = s
    d = 0    

    while x != 0 :
        if   ((d == 0 or d == -1) and check(x, y - 1)) : d = -1; y -= 1
        elif ((d == 0 or d ==  1) and check(x, y + 1)) : d =  1; y +=1
        else :	d = 0; x -= 1

    return y


for tc in range(1, 11):
    input()
    mat = [0] * 100
    for i in range(100):
        mat[i] = list(map(int, input().split()))

    print('#%d'%tc, solve( ))