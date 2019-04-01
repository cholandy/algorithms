# import sys;sys.stdin=open('input1.txt','r')
a=set([2,3])
b=set([3,4])
c=set([1,5])
print(a)
if a|c:
    a=a|c
    print(a)
else:print("no")