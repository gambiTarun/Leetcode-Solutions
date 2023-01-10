# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        q.append(root)
        ans = []
        
        while q:
            s = len(q)
            tmp = []
            for _ in range(s):
                x = q.popleft()
                
                if not x:
                    continue
                
                tmp.append(x.val)
                q.append(x.left)
                q.append(x.right)
                
            if tmp:
                ans.append(tmp)
                
        return ans