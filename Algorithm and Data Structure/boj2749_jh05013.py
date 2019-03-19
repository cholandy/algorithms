m = [1,1,1,0]
def matpow(n):
    if n==1:
        return m
    if n%2==1:
        return prod(m, matpow(n-1))
    else:
        half = matpow(n//2)
        return prod(half, half)
    
def prod(a1, a2):
    return [(a1[0]*a2[0]+a1[1]*a2[2])%1000000,
            (a1[0]*a2[1]+a1[1]*a2[3])%1000000,
            (a1[2]*a2[0]+a1[3]*a2[2])%1000000,
            (a1[2]*a2[1]+a1[3]*a2[3])%1000000]

n=int(input())
print(matpow(n)[1]%1000000)