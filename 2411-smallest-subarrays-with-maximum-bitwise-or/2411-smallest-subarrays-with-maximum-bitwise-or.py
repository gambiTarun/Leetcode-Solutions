class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        last = [0]*32
        res = [0]*len(nums)
        for i in range(len(nums)-1,-1,-1):
            for j in range(32):
                if nums[i] & (1 << j):
                    last[j] = i
            res[i] = max(1, max(last) - i + 1)
        
        return res