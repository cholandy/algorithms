for tc in range(int(input())):
    a,b=input().split()
    i=r=0
    while i<len(a):
        r+=1
        if a[i:i+len(b)]==b:
            i+=len(b)
        else:
            i+=1
    print(r)