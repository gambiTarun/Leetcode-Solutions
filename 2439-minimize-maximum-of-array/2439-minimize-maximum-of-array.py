class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        
        l, r = 0,max(nums)
        
        while l<=r:
            m = l+(r-l)//2
            
            if all(v<=m*(i+1) for i,v in enumerate(accumulate(nums))):  r = m-1
            else:   l = m+1
                
        return l
                