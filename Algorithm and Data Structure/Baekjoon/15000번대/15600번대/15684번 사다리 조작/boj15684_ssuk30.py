N,M,H = map(int,input().split())
line = [[0]*(N-1) for _ in range(H)]
for _ in range(M):
    a,b = map(int, input().split())
    line[a-1][b-1] = 1
        
def check(x,h,cnt):
    if cnt==0:
        for x in range(N):
            cur = x
            for h in range(H):
                if cur<N-1 and line[h][cur]==1: cur+=1
                elif cur>0 and line[h][cur-1]==1: cur-=1
            if cur!=x: return False
        return True
    if h==H: return False
    if x==N-1:
        return check(0,h+1,cnt)
    if line[h][x]==1 or (x>0 and line[h][x-1]) or (x<N-2 and line[h][x+1]):
        return check(x+1,h,cnt)
    else:
        line[h][x] = 1
        if check(x+1,h,cnt-1): return True
        line[h][x] = 0
    if check(x+1,h,cnt): return True
    return False

for i in range(4): 
    if check(0,0,i): print(i);break;
else: print(-1)