class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        res = set()
        nums.sort()
        for i in range(len(nums)):
            res.add(nums[i]+nums[len(nums)-i-1])
            
        return len(res)