class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        best_byfar = nums[0]
        best = nums[0]
        for i in range(1,len(nums)):
            best_byfar = max(best_byfar+nums[i],nums[i])
            best = max(best,best_byfar)
            
        return best