class Trienode:
    def __init__(self):
        self.child = [None]*26
        self.end = False

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        
        ans = []
        
        def addWord(word,root):
            node = root

            for c in word:
                i = ord(c)-ord('a')
                if not node.child[i]:
                    node.child[i] = Trienode()

                node = node.child[i]

            node.end = True

        def findMatch(word,root,build,li):
            node = root

            for c in word:
                i = ord(c)-ord('a')
                if not node.child[i]:
                    return []
                node = node.child[i]
            
            if node.end and len(li)<3:
                li.append(build)

            for i,n in enumerate(node.child):
                if n:
                    build+=chr(ord('a')+i)
                    findMatch("",n,build,li)
                    build=build[:-1]

            
        root = Trienode()
        
        for w in products:
            addWord(w,root)
            
        
        for i,c in enumerate(searchWord):
            tmp = []
            findMatch(searchWord[0:i+1],root,searchWord[0:i+1],tmp)
            ans.append(tmp)
        
        return ans
        
    
                
                