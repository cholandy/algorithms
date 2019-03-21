import sys

class Node:
    def __init__(self, character):
        self.character = character
        self.children = dict()
        self.terminus = False

    def add(self, child_node):
        self.children[child_node.character] = child_node

class Trie:
    def __init__(self):
        self._root = Node(None)

    def insert(self, word):
        if word:
            current_node = self._root
            for character in word:
                if character in current_node.children:
                    current_node = current_node.children[character]
                else:
                    child_node = Node(character)
                    current_node.add(child_node)
                    current_node = child_node
            current_node.terminus = True

    def minimun_search(self, word):
        cnt = 0
        if word:
            current_node = self._root
            for w in word:
                current_node = current_node.children[w]
                if len(current_node.children) != 1 or current_node.terminus:
                    cnt += 1
        return cnt

def search_count(words_list, trie):
    cnt = 0
    for word in word_list:
        cnt += trie.minimun_search(word)
    return cnt

def read_in():
    for line in sys.stdin:
        yield line
    return

reader = read_in()
while True:
    try:
        m = int(next(reader))
        word_list = []
        trie = Trie()
        for _ in range(m):
            target = next(reader).replace('\n', '')
            word_list.append(target)
            trie.insert(target)
        cnt = search_count(word_list, trie)
        print("%.2f" % (cnt / m))
    except StopIteration as e:
        break