# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        def dfs(n):
            if not n:
                return 0
            
            lh = dfs(n.left)
            if lh==-1: return -1
            rh = dfs(n.right)
            if rh==-1: return -1
            
            if abs(lh-rh)>1:
                return -1
            else:
                return max(lh,rh)+1
        
        return dfs(root)!=-1