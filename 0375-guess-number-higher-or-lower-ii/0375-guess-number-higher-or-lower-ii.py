class Solution:
    def getMoneyAmount(self, n: int) -> int:
        
        dp = [[0]*(n+1) for _ in range(n+1)]
        
        for i in range(n,-1,-1):
            for j in range(i,n+1):
                dp[i][j] = min([max(dp[i][x-1],dp[x+1][j])+x for x in range(i,j)], default=0)
        
        return dp[0][n]