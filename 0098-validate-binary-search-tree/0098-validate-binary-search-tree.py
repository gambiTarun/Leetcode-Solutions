# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
#         self.lastv = None
        
#         def dfs(n):
#             if not n:
#                 return True
            
#             if not dfs(n.left):
#                 return False
            
#             if self.lastv!=None and self.lastv>=n.val:
#                 return False
#             self.lastv = n.val
            
#             if not dfs(n.right):
#                 return False
            
#             return True
            
#         return dfs(root)
        
        def dfs(n, mi, ma):
            if not n:
                return True
            
            if (mi!=None and n.val<=mi) or (ma!=None and n.val>=ma):
                return False
            
            if (not dfs(n.left, mi, n.val)) or (not dfs(n.right, n.val, ma)):
                return False
            
            return True
        
        return dfs(root,None,None)
            
        