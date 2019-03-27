def similar(w1, w2):
    diff = [w1.count(c)-w2.count(c) for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ']
    if max(diff) > 1 or min(diff) < -1:
        return False
    return diff.count(1) <= 1 and diff.count(-1) <= 1

n = int(input())
w = input()
res = 0
for i in range(n-1):
    res+= similar(w,input())
print(res)