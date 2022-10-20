class Solution:
    def numberOfNodes(self, n: int, queries: List[int]) -> int:
        
        parent_f = [0]*(n+1)
        for i in queries:
            parent_f[i] += 1
        
        def dfs(s,flips):
            if s>n:
                return 0
            
            flips += parent_f[s]
            res = flips % 2
            return dfs(s*2+1,flips) + dfs(s*2,flips) + res
            
        return dfs(1,0)