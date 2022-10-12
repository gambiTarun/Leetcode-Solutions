class Trienode:
    def __init__(self):
        self.children = [None]*26
        self.wordend = False    
        
class Trie:
        
    def __init__(self):
        self.root = Trienode()

    def insert(self, word: str) -> None:
        node = self.root
        
        for i in word:
            if not node.children[ord(i)-ord('a')]:
                node.children[ord(i)-ord('a')] = Trienode()
            node = node.children[ord(i)-ord('a')]
        
        node.wordend = True

    def search(self, word: str) -> bool:
        node = self.root
        
        for i in word:
            if not node.children[ord(i)-ord('a')]:
                return False
            node = node.children[ord(i)-ord('a')]
        
        return node.wordend

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        
        for i in prefix:
            if not node.children[ord(i)-ord('a')]:
                return False
            node = node.children[ord(i)-ord('a')]
            
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)