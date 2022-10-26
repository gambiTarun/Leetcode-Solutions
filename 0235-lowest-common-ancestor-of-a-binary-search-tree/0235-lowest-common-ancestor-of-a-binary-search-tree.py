# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        def find(n):
            if not n: return        
            if n.val==p.val or n.val==q.val: return n
            
            inl = found(n.left,p)
            inr = found(n.right,q)
            
            if inl and not inr:
                return find(n.left)
            elif inr and not inl:
                return find(n.right)
            
            return n
            
                
        def found(n,x):
            if not n: return False
            if n.val==x.val: return True
            
            return found(n.left,x) or found(n.right,x)
        
        
        return find(root)