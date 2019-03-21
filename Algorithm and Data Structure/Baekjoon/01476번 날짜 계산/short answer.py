import sys
sys.stdin = open('input.txt', 'r')

E,S,M=map(int,input().split())
print((6916*E+4845*S+4200*M-1)%7980+1)