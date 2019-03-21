from math import ceil

def group(n):
    return ceil((-1+(1+8*n)**0.5)/2)+1

x = int(input())
g = group(x) #den+num=group
ind = x-(g-1)*(g-2)//2
if g%2==0:
    print('%d/%d'%(g-ind,ind))
else:
    print('%d/%d'%(ind,g-ind))