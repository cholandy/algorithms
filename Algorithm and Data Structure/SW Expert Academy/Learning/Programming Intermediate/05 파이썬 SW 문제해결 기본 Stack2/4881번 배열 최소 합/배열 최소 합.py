import sys
sys.stdin = open('input.txt', 'r')

def construct_candidates(a, k, input, c):
    in_perm = [False] * NMAX

    for i in range(1, k):
        in_perm[a[i]] = True

    ncandidates = 0
    for i in range(1, input + 1):
        if in_perm[i] == False:
            c[ncandidates] = i
            ncandidates += 1
    return ncandidates


def backtrack(a, k, input):
    global MAXCANDIDATES
    global min_total
    c = [0] * MAXCANDIDATES

    if k == N:
        total_sum = 0
        for i in range(1, k + 1):
            total_sum += array[i-1][a[i]-1]
        if total_sum < min_total :
            min_total = total_sum

    else:
        k += 1
        ncandidates = construct_candidates(a, k, input, c)
        for i in range(ncandidates):
            a[k] = c[i]
            backtrack(a, k, input)



T = int(input())
for tc in range(1, T+1):
    N = int(input())
    array = [list(map(int,input().split())) for x in range (N)]
    u = [0 for i in range(N)] # u = [0, 0, 0]
    min_total = 100 # 최소합
    MAXCANDIDATES = 100
    NMAX = 100
    a = [0] * (N + 1) # a = [0, 0, 0, 0]
    backtrack(a, 0, N)
    print("#%d"%tc, min_total)



# import sys
# sys.stdin = open('input.txt', 'r')
#
# def construct_candidates(a, k, c):
#     in_perm = [False] * N
#
#     for i in range(k):
#         in_perm[a[i]] = True
#
#     ncandidates = 0
#     for i in range(N):
#         if in_perm[i] == False:
#             c[ncandidates] = i
#             ncandidates += 1
#     return ncandidates
#
#
# def backtrack(perm, k, sum):
#     global minV
#     c = [0] * N
#
#     if k == N:
#         if sum < minV : minV = sum
#     else:
#         ncandi = construct_candidates(perm, k, c)
#         for i in range(ncandi):
#             if sum + m[k][c[i]] < minV:
#                 perm[k] = c[i]
#                 backtrack(perm, k + 1, sum + m[k][c[i]])
#
# T = int(input())
# for tc in range(1, T+1):
#     N = int(input())
#     m = [list(map(int,input().split())) for x in range (N)]
#     u = [0 for i in range(N)]
#     minV = 100000
#     perm = [0] * N
#     backtrack(perm, 0, 0)
#     print("#%d"%tc, minV)

