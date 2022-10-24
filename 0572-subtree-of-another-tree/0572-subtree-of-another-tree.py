# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        
        def dfs(n):
            if not n:
                return False
            
            if isIdent(n,subRoot):
                return True
            
            if dfs(n.left) or dfs(n.right):
                return True
            
            return False
        
        def isIdent(n,s):
            if not n and not s:
                return True
            if not n or not s:
                return False
            
            return s.val==n.val and isIdent(n.left,s.left) and isIdent(n.right,s.right)
        
        return dfs(root)
            
            