def makeTrie(words):
    root = {}
    for w in words:
        cd = root
        for l in w: cd = cd.setdefault(l, {})
        cd[''] = ''
    return root

from sys import setrecursionlimit as SRL
SRL(22222)
def contract(trie):
    for desc in trie:
        while 1:
            if len(trie[desc]) > 1: break
            if trie[desc] == '': break
            s = next(iter(trie[desc]))
            if s == '': break
            trie[desc] = trie[desc][s]
        contract(trie[desc])

def totdepth(trie, depth = 0):
    if trie == '': return depth # totdepth, numelements
    return sum(totdepth(trie[desc], depth+1) for desc in trie)

while 1:
    try: n = int(input())
    except: break
    trie = makeTrie([input() for i in range(n)])
    contract(trie)
    print("%.2f"%(totdepth(trie) / n - 1))