class Tower:
    def __init__(self, id, x, y, r):
        self.id = id
        self.x = x
        self.y = y
        self.r = r
        self.neighbor = []

    def check_connect(self, other):
        if (self.x - other.x)**2 + (self.y - other.y)**2 <= (self.r + other.r)**2:
            self.neighbor.append(other)
            other.neighbor.append(self)

T = int(input())
for i in range(T):
    N = int(input())
    tower = []
    for j in range(N):
        x, y, r = map(int, input().split())
        tower.append(Tower(j, x, y, r))

    for j in range(N-1):
        for k in range(j+1, N):
            tower[j].check_connect(tower[k])

    done = []
    num_group = 0
    for j in range(N):
        if tower[j] in done:
            continue
        num_group += 1
        stack = [tower[j]]
        done.append(tower[j])
        while len(stack) > 0:
            t = stack.pop()
            for n in t.neighbor:
                if n not in done:
                    stack.append(n)
                    done.append(n)

    print(num_group)
