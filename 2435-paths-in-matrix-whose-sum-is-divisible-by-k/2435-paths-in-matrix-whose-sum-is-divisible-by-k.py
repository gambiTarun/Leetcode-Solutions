class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m,n = len(grid), len(grid[0])
        mod = 10**9+7
        dp = [[[0]*k for _ in range(len(i))] for i in grid] 
        dp[0][0][grid[0][0]%k] = 1
        
        for i in range(m):
            for j in range(n):
                for m in range(k):
                    if i>0: dp[i][j][(m+grid[i][j])%k] += (dp[i-1][j][m])%mod
                    if j>0: dp[i][j][(m+grid[i][j])%k] += (dp[i][j-1][m])%mod
                    
        return dp[-1][-1][0]%mod