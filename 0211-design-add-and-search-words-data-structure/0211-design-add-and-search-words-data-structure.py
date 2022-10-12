class Trienode:
    def __init__(self):
        self.child = {}
        self.end = False
        
class WordDictionary:

    def __init__(self):
        self.root = Trienode()

    def addWord(self, word: str) -> None:
        node = self.root
        
        for i in word:
            if i not in node.child:
                node.child[i] = Trienode()
            node = node.child[i]
            
        node.end = True

    def search(self, word: str) -> bool:
        def dfs(s, node):

            for i in range(s,len(word)):
                if word[i]!='.':
                    if word[i] not in node.child:
                        return False
                    node = node.child[word[i]]
                else:
                    for x in node.child.values():
                        if dfs(i+1, x):
                            return True
                    return False
            return node.end
        
        return dfs(0, self.root)
                
                


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)