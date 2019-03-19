while True:
    try:
        a,b,c=map(int,input().split())
        r=0
        for i in range(a):
            if b//2**i%2:
                r+=2*4**i
            if c//2**i%2:
                r+=4**i
        print(r)
    except:
        break