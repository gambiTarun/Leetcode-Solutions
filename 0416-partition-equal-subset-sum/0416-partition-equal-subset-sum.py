class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        
        tar = sum(nums)
        
        if tar%2==1:
            return False
        
        tar //= 2
        
        dp = [[False]*(len(nums)+1) for _ in range(tar+1)]
        dp[0][0] = True
        
        for j in range(1,len(nums)+1):
            for i in range(tar+1):
                dp[i][j] = dp[i][j-1]
                if i>=nums[j-1]:
                    dp[i][j] = dp[i][j-1] or dp[i-nums[j-1]][j-1]
                
        return dp[tar][len(nums)]
#         dp = [False]*(tar+1)
#         dp[0] = True
        
#         for j in nums:
#             for i in range(tar,j-1,-1):
#                 dp[i] = dp[i] or dp[i-j]
                    
#         return dp[tar]

        