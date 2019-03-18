from math import ceil

def group(n):
    if n<0:
        return 0
    return ceil((-1+(1+8*n)**0.5)/2)

x = int(input())
print(group((x-2)//6+1)+1)