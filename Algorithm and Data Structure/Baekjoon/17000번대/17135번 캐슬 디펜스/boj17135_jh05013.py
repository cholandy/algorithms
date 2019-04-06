def sim(i, j, k):
    def closest(i, j):
        ans = (9999,)*3
        for ei,ej in es:
            dist = abs(ei-i) + abs(ej-j)
            if dist <= D: ans = min(ans, (dist,ej,ei))
        return ans
        
    es = set(enemy)
    ans = 0
    archer = (i,j,k)
    for ROW in range(n, 0, -1):
        attack = [closest(ROW,j) for j in archer]
        for d,j,i in attack:
            if (i,j) in es: es.remove((i,j)); ans+= 1#; print('killed', (i,j))     
        es = {T for T in es if T[0] != ROW-1}
        #print('advance to', ROW-1)
    return ans

n, m, D = map(int,input().split())
enemy = []
for i in range(n):
    row = input().split()
    for j in range(m):
        if row[j] == '1': enemy.append((i,j))
print(max(sim(i,j,k) for i in range(m) for j in range(i+1,m) for k in range(j+1,m)))