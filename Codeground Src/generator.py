from random import randint
f=open('input.txt', 'w')

arr = [randint(0,1000) for _ in range(1000)]
for i in arr:
    f.write(str(i)+' ')