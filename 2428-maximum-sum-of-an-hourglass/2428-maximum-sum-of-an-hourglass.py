class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        g = grid
        ans = 0
        def sumh(i,j):
            return g[i][j]+sum(g[i+1][j+x] for x in range(-1,2))+sum(g[i-1][j+x] for x in range(-1,2))
        
        for i in range(1,len(g)-1):
            for j in range(1,len(g[0])-1):
                ans = max(ans,sumh(i,j))
                
        return ans