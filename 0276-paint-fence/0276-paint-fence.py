class Solution:
    def numWays(self, n: int, k: int) -> int:
        
        
        dp = [0]*(n+1)
        
        dp[0] = 0
        dp[1] = k
        
        if n==1:
            return dp[n]
        
        dp[2] = k*k
        
        for i in range(3,n+1):
            dp[i] = dp[i-1] * (k-1) + dp[i-2] * (k-1)
            
        return dp[n]