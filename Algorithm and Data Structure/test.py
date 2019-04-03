import sys;sys.stdin=open('input1.txt','r')

def maxidx(a,b):
    idx=0
    for i in range(len(a)-1,-1,-1):
        if a[i]==max(b):
            idx=i
            break
    for j in range(len(b)):
        if b[j]==max(b):
            b.pop(j)
            return idx

 

for tc in range(int(input())):
    num, swap = map(str,input().split())
    cnt=int(swap)
    maxnum=''.join(sorted(list(str(num)),reverse=True))
    original=list(num)
    max_checklist=list(num)
    big_to_small=sorted(list(set(list(num))),reverse=True)
    cc=0
    while cnt>0:
        if ''.join(original)!=maxnum:
            MAX=str(big_to_small[cc])
            key=False
            midx=maxidx(original,max_checklist)
            for i in range(len(original)):
                if original[i]>original[midx]:continue
                if original[i]==original[midx] and original[i]==MAX:break
                if original[i]!=original[midx] and original[i]<MAX:
                    original[i],original[midx]=original[midx],original[i]
                    key=True
                    break
            cc+=1
            if key:
                cnt-=1
                
                    
    print('#{} {}'.format(tc+1,''.join(original)))