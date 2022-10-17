class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        dt = set(nums)
        m = float("-inf")
        
        for i in nums:
            if i>m and -i in dt:
                m = i
        
        return -1 if m==float("-inf") else m