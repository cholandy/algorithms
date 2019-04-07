import sys;sys.stdin=open('input2.txt','r')
from collections import deque
from itertools import *

maps=[list(map(int,input().split())) for _ in range(10)]

possible_list=[[i,j] for i in range(10) for j in range(10) if maps[i][j]]


for candidates in possible_list:
    i,j=candidates
    for i in range(6):
        for j in range(6):
            for x,y in sorted(set(list(permutations(range(i,i+5),2))+list(combinations_with_replacement(range(j,j+5),2)))):
                if maps[x][y]:break
            print("Yeah")