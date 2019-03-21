n=int(input())
sc=list(map(int,input().split()))
m=max(sc)
sco=[float(i/m*100) for i in sc]
z=0
for i in sco:
    z+=i
a=z/n
print("%.2f" %a)