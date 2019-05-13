a=int(input())
for tc in range(a):
    zero,one=1,0
    b=int(input())
    for _ in range(b):
        zero,one=one,zero+one
    print(zero, one)
