import sys; input = lambda: sys.stdin.readline().rstrip()

def mean(n, a) :
    return sum(a)/n
def median(n, a) :
    return a[n//2]
def mode(n, a) :
    mxc, mxv = 0, []
    i = 0
    while i < n :
        j = i
        while j < n and a[i] == a[j] :
            j += 1
        c = j-i
        if c == mxc :
            mxv.append(a[i])
        elif c > mxc :
            mxc = c
            mxv = [a[i]]
        i = j
    return mxv[1] if len(mxv)>1 else mxv[0]
def rng(n, a) :
    return a[n-1] - a[0]


n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
print('{:.0f}'.format(mean(n, a)))
print(median(n,a))
print(mode(n,a))
print(rng(n,a))