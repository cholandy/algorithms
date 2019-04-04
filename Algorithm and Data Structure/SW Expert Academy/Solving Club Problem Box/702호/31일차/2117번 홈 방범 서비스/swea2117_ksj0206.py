import sys;sys.stdin=open('input1.txt','r')
def find(startk):
    k = startk
    while 1:
        cur_coast = k**2 + (k-1)**2
        cur_minhome = (cur_coast//m) if not cur_coast%m else (cur_coast//m)+1 
 
        info = [0 for _ in range(n**2)] 
        for i in range(n):
            for j in range(n):
                for a in range(n):
                    for b in range(n):
                        if mapp[i][j] and i <= j+b-a+k-1 and i <= -j+a+b+k-1 and i >= j+b-a-k+1 and i >= -j+a+b-k+1: 
                            info[a*n+b] += 1 
 
        if max(info) >= cur_minhome: 
            return max(info) 
        else:
            k -= 1
 
T = int(input())
for t in range(1,T+1):
    n,m = map(int,input().split())
    mapp = [ 0 for _ in range(n) ]
    homz = 0 
    for _ in range(n):
        mapp[_] = list(map(int,input().split()))
        homz += sum(mapp[_])
 
    afford = m*homz 
    max_k = 1
    while 1:
        coast = max_k ** 2 + (max_k - 1) ** 2
        if afford - coast >= 0: 
            max_k += 1
        else: 
            break            
    max_k -= 1 

    print("#{} {}".format(t,find(max_k)))