from itertools import *
a=sorted(set(list(permutations(range(1,6),2))+list(combinations_with_replacement(range(1,6),2))))
for i in a:
    print(i)