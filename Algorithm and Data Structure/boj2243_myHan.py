import sys
class BIT:
	def __init__(self, size, origin = None):
		self.treeSize = size+1
		self.tree = [0] * self.treeSize
		if origin is not None:
			for i, o in enumerate(origin):
				self.add(i+1, o)
	def add(self, idx, val):
		while idx < self.treeSize:
			self.tree[idx] += val
			idx += (idx & -idx)
	def __sum(self, end):
		res = 0
		idx = end-1
		while idx > 0:
			res += self.tree[idx]
			idx -= (idx & -idx)
		return res

	def sum(self, begin, end):
		return self.__sum(end) - self.__sum(begin)

	def change(self, idx, val):
		# print("change: {0}({1}) -> {2}".format(idx, self.sum(idx, idx+1), val))
		self.add(idx, val-self.sum(idx, idx+1))

inp = sys.stdin.read()

def getLine():
	global inp
	for line in inp.splitlines():
		yield line

gen = getLine()

def binsearch(tree, val):
	top = 1000000
	bot = 1
	while top != bot:
		# print(top, bot)
		if tree.sum(1, (top + bot)//2+1) >= val:
			top = (top + bot)//2
		else:
			bot = (top + bot)//2 + 1
	return top


N = int(next(gen))
tree = BIT(1000000)
for _ in range(N):
	query = next(gen)
	# print(tree.tree[:20])
	if query[0] == '1':
		A, B = map(int, query.split())
		res = binsearch(tree, B)
		print(res)
		tree.add(res, -1)
	else:
		A, B, C = map(int, query.split())
		tree.add(B, C)