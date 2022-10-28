class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        
        l,r,z = 0,0,-1
        res = 0
        while r<len(nums):
            if nums[r]==0:
                if z!=-1: 
                    l = z+1
                z = r
            
            res = max(res,r-l+1)
                
            r += 1
            
        return res