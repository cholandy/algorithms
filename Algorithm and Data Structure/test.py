import itertools
import sys;sys.stdin=open('input1.txt','r')


def line_check(li, k):
    cnt = 1

    for i in range(len(li)-1):
        if li[i] == li[i+1]:
            cnt += 1
        else:
            cnt = 1

        if cnt >= k:
            return True
    return False


def check(li):
    for w in range(W):
        if not line_check([li[d][w] for d in range(D)], K):
            return False
    return True


def chemical(li_combs):
    for i in range(len(li_combs)):
        comb = list(li_combs[i])

        for q in range(1<<len(comb)):
            subsets = []
            for p in range(len(comb)):
                if q & 1<<p:
                    subsets.append(p)

            temp_li = li[:]
            for q in range(len(comb)):
                if q in subsets:
                    temp_li[comb[q]] = [1]*W
                else:
                    temp_li[comb[q]] = [0]*W
            if check(temp_li):
                return True
    return False


T = int(input())

for t in range(T):
    D, W, K = map(int, input().split())
    li = []
    result = 0
    tf = True

    for d in range(D):
        li.append(list(map(int, input().split())))

    if not check(li):
        for i in range(1, K):
            if chemical(list(itertools.combinations(range(D), i))):
                result = i
                tf = False
                break
        if tf:
            result = K

    print("#{} {}".format(t+1, result))