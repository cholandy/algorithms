a,b=1,0
for i in range(int(input())%1500000):
    a,b=b,(a+b)%1000000
print(b)