class Node :
    SORT_KEY = lambda x:x.num
    def __init__(self, num) :
        self.num = num
        self.con = []

    def connect(self, other) :
        if other not in self.con :
            self.con.append(other)
            other.con.append(self)

    def __repr__(self) :
        return 'Node {}'.format(self.num)
    def __str__(self) :
        return repr(self)


class Graph :
    def __init__(self, size) :
        self.nodes = [Node(i) for i in range(size)]

    def __len__(self) :
        return len(self.nodes)

    def connect(self, ia, ib) :
        self.nodes[ia].connect(self.nodes[ib])

    def dfs(self, startidx) :
        retst = [self.nodes[startidx]]
        result = []
        visited = [False for i in range(len(self))]
        while len(retst) :
            node = retst.pop()
            if visited[node.num] :
                continue
            result.append(node.num)
            visited[node.num] = True
            for nd in sorted(node.con, reverse=True,
                             key=Node.SORT_KEY) :
                if not visited[nd.num] :
                    retst.append(nd)
        return result

    def bfs(self, startidx) :
        tskqu = [self.nodes[startidx]]
        result = []
        visited = [False for i in range(len(self))]
        while len(tskqu) :
            node = tskqu.pop(0)
            if visited[node.num] :
                continue
            result.append(node.num)
            visited[node.num] = True
            for nd in sorted(node.con, key=Node.SORT_KEY) :
                if not visited[nd.num] :
                    tskqu.append(nd)
        return result

import sys
input = lambda: sys.stdin.readline().rstrip()
n, m, v = map(int, input().split())
g = Graph(n)
for i in range(m) :
    a, b = map(int, input().split())
    g.connect(a-1, b-1)
dfsres = ' '.join(str(i+1) for i in g.dfs(v-1))
bfsres = ' '.join(str(i+1) for i in g.bfs(v-1))
print(dfsres)
print(bfsres)