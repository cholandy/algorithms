while 1:
    s=input()
    if s=='0':
        break
    else:
        N,*L=map(int,s.split())
        T=[]
        def p(i,c):
            global N,L,T
            if c==6:
                print(' '.join(map(str,T)))
            else:
                for j in range(i,N):
                    T+=[L[j]]
                    p(j+1,c+1)
                    T.pop()
        p(0,0)
        print()