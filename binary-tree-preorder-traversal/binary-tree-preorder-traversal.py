# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res, st = [], []
        curr = root
        while len(st)>0 or curr:
            if curr:
                st.append(curr)
                res.append(curr.val)
                curr=curr.left
            else:
                curr=st.pop()
                curr=curr.right
        return res
            