import sys
sys.setrecursionlimit(3000)
X,Y=input(),input()
C=[[0]*(len(Y)+1) for i in range(len(X)+1)]
for i in range(len(X)):
    for j in range(len(Y)):
        if X[i]==Y[j]:
            C[i+1][j+1]=C[i][j]+1
        else:
            C[i+1][j+1]=max(C[i+1][j],C[i][j+1])
def b(i,j):
    if i==-1 or j==-1:
        return ''
    elif X[i]==Y[j]:
        return b(i-1,j-1)+X[i]
    elif C[i+1][j]>C[i][j+1]:
        return b(i,j-1)
    else:
        return b(i-1,j)
print(C[-1][-1])
print(b(len(X)-1,len(Y)-1))