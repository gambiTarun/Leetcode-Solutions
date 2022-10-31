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
            d[n] = []
            
            for x in n.neighbors:
                if x not in d:
                    dfs(x)
                    
                d[n].append(x)
                
        def dfscreate(n,d):
            if not n:
                return Node()
            
            node = Node(n.val)
            vis[n] = node
            for x in d[n]:
                if x not in vis:
                    node.neighbors.append(dfscreate(x,d))
                else:
                    node.neighbors.append(vis[x])
            
            return node
            
        dfs(node)
        vis = {}
        
        return dfscreate(node,d) if d else None
        