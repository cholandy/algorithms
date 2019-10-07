def Z(n,r,c):
    if n==1:
        return 2*r+c
    half = 1<<(n-1)
    qs = half**2
    if r<half and c<half:
        return Z(n-1,r,c)
    if r<half and c>=half:
        return qs+Z(n-1,r,c-half)
    if r>=half and c<half:
        return 2*qs+Z(n-1,r-half,c)
    return 3*qs+Z(n-1,r-half,c-half)

n,r,c = map(int,input().split())
print(Z(n,r,c))