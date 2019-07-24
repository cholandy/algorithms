from random import randint
f=open('input.txt', 'w')

arr = [randint(0,100000000) for _ in range(10000000)]
f.write('10000000\n')
for i in arr:
    f.write(str(i)+' ')