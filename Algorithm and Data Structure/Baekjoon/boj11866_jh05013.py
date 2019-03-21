n, m = map(int,input().split())
L = []
table = list(range(1,n+1))
for i in range(n):
    elim = (m-1)%len(table)
    L.append(table[elim])
    table = table[elim+1:]+table[:elim]
print("<"+str(L)[1:-1]+">")