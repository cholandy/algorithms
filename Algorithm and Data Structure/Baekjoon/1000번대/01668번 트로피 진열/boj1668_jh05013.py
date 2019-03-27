def sight(h):
    maxh = 0
    res = 0
    for i in h:
        if maxh < i:
            res+= 1
            maxh = i
    return res

n = int(input())
h = [int(input()) for i in range(n)]
print(sight(h))
print(sight(h[::-1]))