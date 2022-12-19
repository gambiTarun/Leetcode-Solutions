class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k<2: return 0
        
        prod,l,r = 1,0,0
        ans = 0
        
        while r<len(nums):
            prod *= nums[r]
            while prod>=k:
                prod//=nums[l]
                l+=1
            ans += r-l+1
            r+=1
            
        return ans
                