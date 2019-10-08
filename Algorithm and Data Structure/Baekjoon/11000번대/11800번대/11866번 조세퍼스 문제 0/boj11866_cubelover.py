n,m=map(int,input().split())
d=[i+1 for i in range(n)]
r=[]
j=0
for tc in range(n):
    j=(j+m-1)%len(d)
    r.append(d[j])
    d.remove(d[j])
print("<"+', '.join(map(str,r))+">")