for tc in range(int(input())):
    n=int(input())
    for i in range(111):
        if i+i*i>n:
            break
    print(i-1)