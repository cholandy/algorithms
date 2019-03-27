def dnc(a, i, j): #answer of a[i:j]
    if j-i == 1:
        return a[i]
    mid = (i+j)//2
    va = dnc(a, i, mid)
    vb = dnc(a, mid, j)
    
    pi = mid-1
    pj = mid
    minv = min(a[pi], a[pj])
    best = max(va,vb,minv*2)
    while pi!=i or pj!=j-1:
        #print(i,j,'//',pi,pj,minv,best)
        if pi==i:
            pj+= 1
        elif pj==j-1:
            pi-= 1
        elif a[pi-1] > a[pj+1]:
            pi-= 1
        else:
            pj+= 1
        minv = min(minv, a[pi], a[pj])
        best = max(best, minv*(pj-pi+1))
    #print(i,j,'//',best)
    return best

def solve(a):
    return dnc(a, 0, len(a))

while 1:
    L = list(map(int,input().split()))[1:]
    if L == []:
        break
    print(solve(L))