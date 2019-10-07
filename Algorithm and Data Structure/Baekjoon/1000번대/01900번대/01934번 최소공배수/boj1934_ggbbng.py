class Prime:
    def __init__(self):
        self.prime = [True for i in range(10000)]
        for i in range(2, 10000):
            if self.prime[i]:
                for j in range(i*2, 10000, i):
                    self.prime[j] = False

    def is_prime(self, n):
        return self.prime[n]


class Key:
    def __init__(self):
        self.prime = Prime()

    def get(self, original, target):
        if original == target:
            return 0
        distance = [-1 for i in range(10000)]
        distance[original] = 0
        count = 0
        stack = []
        stack2 = [original]
        while stack or stack2:
            if not stack:
                count += 1
                stack = stack2
                stack2 = []
            n = stack.pop()
            for k in range(4):
                m0 = n - (n // 10 ** k % 10)*10**k
                for i in range(10):
                    m = m0 + i*(10**k)
                    if m == target:
                        return count
                    if m >= 1000 and self.prime.is_prime(m) and distance[m] == -1:
                        stack2.append(m)
                        distance[m] = count
        return 'Impossible'


T = int(input())
key = Key()
for _ in range(T):
    original, target = map(int, input().split())
    print(key.get(original, target))

