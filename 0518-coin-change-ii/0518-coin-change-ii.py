class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
#         dp = [[0]*(len(coins)) for _ in range(amount+1)]
#         dp[0][0] = 1
        
#         for i in range(len(coins)):
#             dp[0][i] = 1
            
#         for i in range(amount+1):
#             if i%coins[0]==0:
#                 dp[i][0] = 1
            
#         for i in range(1,amount+1):
#             for j in range(1,len(coins)):
#                 dp[i][j] = dp[i][j-1]
#                 if i>=coins[j]:
#                     dp[i][j] += dp[i-coins[j]][j]
        
#         return dp[amount][len(coins)-1]

        dp = [0]*(amount+1)
        dp[0] = 1
        
        for c in coins:
            for i in range(amount+1):
                if i>=c:
                    dp[i] += dp[i-c]
                    
        return dp[amount]