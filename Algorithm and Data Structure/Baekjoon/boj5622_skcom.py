a = [3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10]

b = input()
s = 0
for i in range(0, len(b)):
    s+=a[ord(b[i])-ord('A')]

print(s)
