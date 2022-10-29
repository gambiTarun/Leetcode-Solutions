class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        
#         dp = [[0]*(len(nums)) for _ in range(target+1)]
        
#         for i in range(len(nums)):
#             dp[0][i] = 1
            
#         for i in range(target+1):
#             if i%nums[0]==0:
#                 dp[i][0] = 1
                
                
#         for i in range(1,target+1):
#             for j in range(1,len(nums)):
#                 dp[i][j] = dp[i][j-1]
#                 if i>=nums[j]:
#                     dp[i][j] += dp[i-nums[j]][j]
                    
#         return dp[target][len(nums)-1]


        dp = [0]*(target+1)
        dp[0] = 1
        for i in range(target+1):
            for n in nums:
                if i>=n:
                    dp[i] += dp[i-n]
                    
        return dp[target]