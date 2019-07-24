from random import randint
f=open('input.txt', 'w')

arr = [randint(0,100000) for _ in range(100000)]
f.write('100000\n')
for i in arr:
    f.write(str(i)+' ')