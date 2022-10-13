# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        res = []
        
        def dfs(n):
            if not n:
                return 0
            
            lh = dfs(n.left)
            rh = dfs(n.right)
            
            res.append(abs(lh-rh)<2)
            
            return max(lh,rh)+1
        
        dfs(root)
        return all(res)