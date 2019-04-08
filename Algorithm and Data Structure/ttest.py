from random import randint

for q in range(50):
    b=10
    d=randint(1,b)
    a=[[randint(0,1) for _ in range(b)] for _ in range(b)]
    # print(b,b,d)
    [print(*i) for i in a]