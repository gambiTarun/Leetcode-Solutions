# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        
        s = set()
        q = deque()
        c = root
        while q or c:
            if c:
                q.append(c)
                c = c.left
            else:
                c = q.pop()
                if k-c.val in s:
                    return True
                s.add(c.val)
                c = c.right
                
        return False