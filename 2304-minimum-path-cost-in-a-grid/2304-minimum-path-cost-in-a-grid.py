class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        dp = [[0]*n for _ in range(m)]
        dp[0] = grid[0].copy()
        
        for i in range(1,m):
            for j in range(n):
                dp[i][j] = min([moveCost[grid[i-1][k]][j]+dp[i-1][k] for k in range(n)]) + grid[i][j]
                
        
        return min(dp[-1])