# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        
        if not root:
            return []
        
        self.prev = None
        self.maxC = 0
        self.curC = 0
        self.res = []
        
        def dfs(node):
            if not node:
                return None
        
            dfs(node.left)
        
            self.curC = 1 if node.val!=self.prev else self.curC+1
            
            if self.curC > self.maxC:
                self.res = [node.val]
                self.maxC = self.curC
            elif self.curC == self.maxC:
                self.res.append(node.val)
            
            self.prev = node.val 
            
            dfs(node.right)
            
        dfs(root)
        return self.res
            
                