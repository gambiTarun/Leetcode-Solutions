class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        dp = [[0]*n for _ in range(n)]
        dp[0] = matrix[0]
        
        for i in range(1,n):
            for j in range(n):
                dp[i][j] = min(dp[i-1][j-1 if j-1>=0 else j],dp[i-1][j],dp[i-1][j+1 if j+1<n else n-1]) + matrix[i][j]
                
        # print(dp)
        return min(dp[-1])