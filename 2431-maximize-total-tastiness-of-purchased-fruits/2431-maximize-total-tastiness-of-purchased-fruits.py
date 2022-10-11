class Solution:
    def maxTastiness(self, price: List[int], tastiness: List[int], maxAmount: int, maxCoupons: int) -> int:
        
        dp = [[[0]*(maxCoupons+1) for _ in range(maxAmount+1)] for _ in range(len(price)+1)]
        
        for i in range(1,len(price)+1):
            for j in range(maxAmount+1):
                for k in range(maxCoupons+1):
                    dp[i][j][k] = dp[i-1][j][k]
                    if j-price[i-1]>=0:
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-price[i-1]][k]+tastiness[i-1])
                    if k>0 and j-price[i-1]//2>=0:
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-price[i-1]//2][k-1]+tastiness[i-1])
                        
        return dp[len(price)][maxAmount][maxCoupons]