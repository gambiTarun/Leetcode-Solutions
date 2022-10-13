# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        self.lastv = None
        
        def dfs(n):
            if not n:
                return True
            
            if not dfs(n.left):
                return False
            
            if self.lastv!=None and self.lastv>=n.val:
                return False
            self.lastv = n.val
            
            if not dfs(n.right):
                return False
            
            return True
            
        return dfs(root)