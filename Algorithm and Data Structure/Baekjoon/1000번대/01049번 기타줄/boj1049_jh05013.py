N, BRAND = map(int,input().split())
pack = 9999
indv = 9999
for i in range(BRAND):
    a, b = map(int,input().split())
    pack = min(pack, a)
    indv = min(indv, b)

pnum, inum = divmod(N, 6)
print(min(pnum*pack + min(inum*indv, pack), N*indv))