n = int(input())
end = [0,1,1,1,1,1,1,1,1,1]

def get(L, x):
    if 0 <= x < len(L):
        return L[x]
    return 0

for i in range(n-1):
    end = [get(end,x-1)+get(end,x+1) for x in range(10)]
print(sum(end)%1000000000)