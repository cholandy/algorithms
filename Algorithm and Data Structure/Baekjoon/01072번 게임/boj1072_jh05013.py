# (y+n)*100/(x+n) >= z
# 100y + 100n >= zx + zn
# (100-z)n >= zx-100y

from math import ceil
while 1:
    try: x, y = map(int,input().split())
    except: exit()
    z = y*100//x
    if z >= 99: print(-1); continue
    z+= 1
    print(ceil((z*x-100*y)/(100-z)))