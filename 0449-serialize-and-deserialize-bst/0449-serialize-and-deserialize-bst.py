# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        def postorder(root):
            return postorder(root.left) + postorder(root.right) + [root.val] if root else []
        
        # print(' '.join(map(str, postorder(root))))
        return ' '.join(map(str, postorder(root)))
        

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        def create(l=float('-inf'),h=float('inf')):
            if not data or data[-1]<l or data[-1]>h:
                return None
            
            val = data.pop()
            root = TreeNode(val)
            root.right = create(val,h)
            root.left = create(l,val)

            return root
        
        data = [int(x) for x in data.split(' ') if x]
        return create()
            
            
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans