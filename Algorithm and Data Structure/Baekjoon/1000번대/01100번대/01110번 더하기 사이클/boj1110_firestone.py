n = int(input())
o = n
cnt =1
while True:
    a, b = n//10, n%10
    c = (a+b)%10
    n = 10*b+c
    if n == o:
        break
    else:
        cnt +=1
print(cnt)