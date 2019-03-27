for _ in range(int(input())):
    ret = [
    ['TTT',0],
    ['TTH',0],
    ['THT',0],
    ['THH',0],
    ['HTT',0],
    ['HTH',0],
    ['HHT',0],
    ['HHH',0],
    ]
    case=input()
    for i in range(38):
        a=case[i:i+3]
        for j in range(8):
            if ret[j][0]==a:
                ret[j][1]+=1
                break
    [print(i[1],end=' ') for i in ret]
    print()