for _ in range(int(input())):
    seq=input()
    N=int(input())
    s=input()
    if s=='[]':
        arr=[]
    else:
        arr=list(map(int,s[1:-1].split(',')))
    i,j=0,N
    r=False
    for s in seq:
        if s=='R':r^=1
        else:
            if r:
                j-=1
            else:
                i+=1
    if i>j:
        print('error')
    else:
        if r:
            print(str(arr[i:j][::-1]).replace(' ',''))
        else:
            print(str(arr[i:j]).replace(' ',''))