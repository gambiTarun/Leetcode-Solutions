# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        
#         st = deque()
#         res = []
#         curr = root
        
#         while st or curr:
            
#             if curr:
#                 st.append(curr)
#                 res.insert(0,curr.val)
#                 curr = curr.right
#             else:
#                 curr = st.pop()
#                 curr = curr.left
                
                
#         return res

#         res = []
#         if not root: return res
        
#         st = deque()
#         st += [root]*2
    
#         while st:
#             curr = st.pop()
#             if st and st[-1]==curr:
#                 if curr.right: st += [curr.right]*2
#                 if curr.left: st += [curr.left]*2
#             else:
#                 res.append(curr.val)
    
#         return res

        st = deque()
        curr = root
        res = []
        
        while st or curr:
            if curr:
                st.append(curr)
                curr = curr.left
            else:
                temp = st[-1].right
                if not temp:
                    temp = st.pop()
                    res.append(temp.val)
                    while st and temp==st[-1].right:
                        temp = st.pop()
                        res.append(temp.val)
                else:
                    curr = temp
        
        return res
                    