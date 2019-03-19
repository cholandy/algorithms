def nextperm(a):
    ln = len(a); k = ln - 1
    while a[k] < a[k-1]: k-= 1
    if not k: return [-1]
    unused = a[k:]; del a[k:]
    mx = min(x for x in unused if x > a[k-1])
    unused.append(a[k-1]); a[k-1] = mx
    unused.remove(mx); a+= sorted(unused)
    return a

dig = [
    "000000 001100 010010 010010 010010 001100 000000",
    "000000 000100 001100 000100 000100 000100 000000",
    "000000 011110 000010 011110 010000 011110 000000",
    "000000 011100 000010 000100 000010 011100 000000",
    "000000 000100 001100 010100 111110 000100 000000",
    "000000 011110 010000 011100 000010 010010 001100",
    "000000 010000 010000 011110 010010 011110 000000",
    "000000 011110 000010 000100 000100 000100 000000",
    "000000 011110 010010 011110 010010 011110 000000",
    "011110 010010 010010 011110 000010 000010 000010"]
for i in range(10): dig[i] = dig[i].split()

def match(i):
    snip = [board[row][i:i+6] for row in range(7)]
    return dig.index(snip)

board = [input() for i in range(7)]
p = nextperm([match(i) for i in range(0, len(board[0]), 6)])
if p[0] == -1: print("The End")
else:
    for row in range(7): print(''.join(dig[x][row] for x in p))