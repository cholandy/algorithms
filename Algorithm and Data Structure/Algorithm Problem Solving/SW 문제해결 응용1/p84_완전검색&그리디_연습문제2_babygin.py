numa = [456789123, 333000292,111293293,222111123]
for k in range(len(numa)):
    num=numa[k]
    c = [0] * 12
    for i in range(9):
        c[num%10] += 1
        num //= 10
    print(c)
    i = 0
    tri = run = 0
    while i < 10:
        if c[i] >=3:
            c[i] -=3
            tri +=1
            continue
        if c[i] >=1 and c[i+1]>=1 and c[i+2]>=1:
            c[i] -=1
            c[i+1]-=1
            c[i+2]-=1
            run +=1
            continue
        i += 1
    if run+tri == 3: print("True")
    else: print("Lose")
