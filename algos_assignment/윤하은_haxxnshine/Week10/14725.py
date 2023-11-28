import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

# key와 children(dict)을 저장할 Node 클래스
class Node:
    def __init__(self, key):
        self.key = key
        self.children = dict()
    
# Trie 자료구조 클래스
class Trie:
    def __init__(self):
        self.head = Node(None)
    
    def insert(self, words):
        now = self.head
        for word in words:
            if word not in now.children:
                now.children[word] = Node(word)
            now = now.children[word]
    
    def visualize(self, level, now):
        if not level:
            now = self.head
        for child in sorted(now.children.keys()):
            print("--" * level, end="")
            print(child)
            self.visualize(level + 1, now.children[child])

trie = Trie()
N = int(input())
for _ in range(N):
    each = input().rstrip().split()[1:]
    trie.insert(each)
trie.visualize(0, None)
