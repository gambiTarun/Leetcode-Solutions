# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        st = deque()
        res = []
        curr = root
        
        while st or curr:
            
            if curr:
                res.append(curr.val)
                st.append(curr)
                curr = curr.left
            else:
                curr = st.pop()
                curr = curr.right
                
        return res