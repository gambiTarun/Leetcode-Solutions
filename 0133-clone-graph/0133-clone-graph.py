"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        
        d = {}
        
        def dfs(n):
            if not n:
                return 
            
            node = Node(n.val)
            d[n] = node
            
            for x in n.neighbors:
                if x not in d:
                    node.neighbors.append(dfs(x))
                else:
                    node.neighbors.append(d[x])
                    
            return node
                
#         def dfscreate(n,d):
#             if not n:
#                 return Node()
            
#             node = Node(n.val)
#             vis[n] = node
#             for x in d[n]:
#                 if x not in vis:
#                     node.neighbors.append(dfscreate(x,d))
#                 else:
#                     node.neighbors.append(vis[x])
            
#             return node
            
        return dfs(node)
        