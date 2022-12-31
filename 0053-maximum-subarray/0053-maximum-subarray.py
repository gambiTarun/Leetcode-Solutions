class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        cursum = 0
        res = -10000
        for i in nums:
            cursum = max(i,cursum+i)
            res = max(res,cursum)
            
        return res
            