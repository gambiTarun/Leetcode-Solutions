class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [1e5]*(amount+1)
        dp[0]=0
        for i in range(amount+1):
            for j in coins:
                if i>=j:
                    dp[i] = min(dp[i],dp[i-j]+1)
                    
        return dp[amount] if dp[amount]!=1e5 else -1