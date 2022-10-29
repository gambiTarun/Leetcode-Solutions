class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        m = len(points)
        n = len(points[0])
        dp = [[0]*n for _ in range(m)]
        dp[0] = points[0].copy()
        
        for i in range(1,m):
            tmpl = [-1]*n
            tmpr = [-1]*n
            
            tmpl[0] = dp[i-1][0]
            for k in range(1,n):
                tmpl[k] = max(tmpl[k-1], dp[i-1][k] + k)
                
            tmpr[-1] = dp[i-1][-1] - n + 1
            for k in range(n-2,-1,-1):
                tmpr[k] = max(tmpr[k+1], dp[i-1][k] - k)
                
            for j in range(n):
                dp[i][j] = max(tmpl[j] - j, tmpr[j] + j) + points[i][j]
                
        return max(dp[-1])