class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        
        if len(nums)==1:
            return -1
        
        if len(nums)==2:
            return sum(nums) if sum(nums)<k else -1
        
        nums.sort()
        maxx = -1
        
        for i in range(len(nums)):
            if nums[i]>k:
                continue
            l,r,m = 0,len(nums)-1,0
            
            while l<r:
                m = l+(r-l)//2
                
                if nums[i]+nums[m]<k:
                    l+=1
                else:
                    r-=1
            if nums[i]+nums[m]<k and m!=i:
                maxx = max(maxx,nums[i]+nums[m])
            
        return maxx