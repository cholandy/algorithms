from itertools import combinations as comb
L,C = map(int,input().split())
for p in comb(''.join(sorted(input().replace(' ',''))), L):
    if 1 <= sum(p.count(c) for c in 'aeiou') <= L-2 :
        print(''.join(p))