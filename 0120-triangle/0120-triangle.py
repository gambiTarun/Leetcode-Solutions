class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        dp = [[0]*i for i in range(1,n+1)]
        dp[0] = triangle[0]
        
        for i in range(1,n):
            for j in range(i+1):
                dp[i][j] = triangle[i][j] + min(dp[i-1][j if j<i else j-1],dp[i-1][j-1 if j-1>=0 else j])
                
        return min(dp[-1])