# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
#         def dfs(n,p,q):
#             if not n:
#                 return None
            
#             pinleft = covers(n.left,p)
#             qinleft = covers(n.left,q)

#             if pinleft^qinleft: return n
            
#             return dfs(n.left,p,q) if pinleft else dfs(n.right,p,q)
            
#         def covers(p,q):
#             if not p:
#                 return False
#             if p==q: return True
#             return covers(p.left,q) or covers(p.right,q)
        
#         if covers(p,q): return p
#         if covers(q,p): return q
#         return dfs(root,p,q)

        if root in (None, p, q): return root
    
        left = self.lowestCommonAncestor(root.left,p,q)
        right = self.lowestCommonAncestor(root.right,p,q)
        
        return root if left and right else (left if left else right)