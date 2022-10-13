# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
#         ans = []
        
#         def inord(n):
#             if not n:
#                 return
            
#             inord(n.left)
#             ans.append(n.val)
#             inord(n.right)
            
#         inord(root)
#         return ans

        st = deque()
        res = []
        curr = root
            
        while st or curr:
            
            if curr:
                st.append(curr)
                curr = curr.left
            else:
                curr = st.pop()
                res.append(curr.val)
                
                curr = curr.right
                
                
        return res
                
            