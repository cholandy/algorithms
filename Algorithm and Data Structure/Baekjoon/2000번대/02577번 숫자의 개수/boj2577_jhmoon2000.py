import sys
a=str(eval('*'.join(map(str.strip, sys.stdin)))).count
for i in range(10):
    print(a(str(i)))