def cw(i, left, right):
    cog[i] = 128*(cog[i]%2) + cog[i]//2
    if left and i and cog[i]&1 != (cog[i-1]&32)//32: ccw(i-1, True, False)
    if right and i<3 and (cog[i]&16)//16 != (cog[i+1]&2)//2: ccw(i+1, False, True)
    
def ccw(i, left, right):
    cog[i] = (cog[i]*2)%256 + cog[i]//128
    if left and i and (cog[i]&4)//4 != (cog[i-1]&32)//32: cw(i-1, True, False)
    if right and i<3 and (cog[i]&64)//64 != (cog[i+1]&2)//2: cw(i+1, False, True)

a1 = int(input(), 2)
a2 = int(input(), 2)
a3 = int(input(), 2)
a4 = int(input(), 2)
cog = [a1, a2, a3, a4]
k = int(input())
for i in range(k):
    ci, di = map(int,input().split())
    if di == 1: cw(ci-1, True, True)
    else: ccw(ci-1, True, True)
print(sum(cog[i]//128*(2**i) for i in range(4)))