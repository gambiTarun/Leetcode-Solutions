class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        
        dp = [[0]*3 for _ in range(len(costs))]
        dp[0] = costs[0]
        
        for i in range(1,len(costs)):
            for j in range(3):
                dp[i][j] = costs[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3])
                
        return min(dp[-1])