class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        
        l, r = 0,max(nums)
        
        while l<=r:
            m = l+(r-l)//2
            
            if any(v>m*(i+1) for i,v in enumerate(accumulate(nums))):  l = m+1
            else:   r = m-1
                
        return l
                