n = [1,1,1,2,2]
for i in range(95):
    n.append(n[-1]+n[-5])
for T in range(int(input())):
    print(n[int(input())-1])