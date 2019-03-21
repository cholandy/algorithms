def do_dp():
    n = input()
    size = list(map(int,raw_input().split()))
    presum = [size[0]] # sum from 0 to i
    for i in xrange(n-1):
        presum.append(presum[-1] + size[i+1])
    opt = [[(float('inf'))]*n for i in xrange(n)]
    pick = [[0]*n for i in xrange(n)]
    # [i][j] = combine from i to j
    for i in xrange(n):
        opt[i][i] = 0
        pick[i][i] = i
    for s in xrange(1, n):
        for i in xrange(n-s):
            j = i+s
            for k in xrange(pick[i][j-1], pick[i+1][j]+1):
                val = opt[i][k-1] + opt[k][j] + presum[j] - (presum[i-1] if i else 0)
                if val < opt[i][j]: opt[i][j] = val; pick[i][j] = k
    print(opt[0][-1])

for T in xrange(input()): do_dp()